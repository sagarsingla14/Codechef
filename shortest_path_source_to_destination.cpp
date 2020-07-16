#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

vector <pair <ll , ll> > graph[100001];
vector <ll> visited(100001 , 0);
vector <ll> ans;
vector <ll> parent(100001 , 0);

void dijkstras(ll s , ll d) {
    priority_queue <pair <ll , ll> , vector <pair <ll , ll>> , greater <pair <ll , ll>>> pq;
    vector <ll> dp(100001 , INFI);
    
    dp[s] = 0;
    pq.push({0ll , s});
    parent[s] = s;
    visited[s] = 1;

    while(!pq.empty()) {
        ll weight = pq.top().first;
        ll node = pq.top().second;
        visited[node] = 1;
        pq.pop();

        for(auto i : graph[node]) {
            if(!visited[i.first] && weight + i.second < dp[i.first]) {
                dp[i.first] = weight + i.second;
                parent[i.first] = node;
                pq.push({dp[i.first] , i.first});
            }
        }
    }

    if(dp[d] == INFI) {
        cout << -1 << endl;
    }
    else {
        while(parent[d] != d) {
            ans.push_back(d);
            d = parent[d];
        }
        ans.push_back(s);
        reverse(ans.begin() , ans.end());

        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    fast_io
    ll n , m;
    cin >> n >> m;

    for(ll i = 0 ; i < m ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }

    dijkstras(1 , n);
    return 0;
}
