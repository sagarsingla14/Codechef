#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 10000000000000


void dijkstras(ll s , ll d , vector <pair <ll , ll>> graph[] , vector <ll> &dp , vector <ll> &parent , vector <ll> &visited) {
    priority_queue <pair <ll , ll> , vector <pair <ll , ll>> , greater <pair <ll , ll>>> pq;
    vector <ll> ans;

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
        cout << "NO" << endl;
    }
    else {
        cout << dp[d] << endl;
    }
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        vector <pair <ll , ll> > graph[n + 1];
        vector <ll> dp(n + 1 , INFI);
        vector <ll> parent(n + 1 , 0);
        vector <ll> visited( + 1 , 0);


        for(ll i = 0 ; i < m ; i++) {
            ll u , v , w;
            cin >> u >> v >> w;
            graph[u].push_back({v , w});
        }

        ll src , des;
        cin >> src >> des;
        dijkstras(src , des , graph , dp , parent , visited);
    }
    return 0;
}
