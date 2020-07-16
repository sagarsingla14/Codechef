#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m , ans , lib , road;
vector <ll> graph[100001];
ll visited[100001];
ll degree[100001];

void bfs(ll start) {
    visited[start] = 1;
    queue <ll> q;
    q.emplace(start);
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto i : graph[parent]) {
            if(!visited[i]) {
                road ++;
                q.emplace(i);
                visited[i] = 1;
            }
        }
    }
}

bool sortBySec(pair <ll , ll> a , pair <ll , ll> b) {
    return a.second > b.second;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , l , r;
        cin >> n >> m >> l >> r;
        memset(visited , 0 , sizeof(visited));
        memset(degree , 0 , sizeof(degree));

        for(ll i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u] ++;
            degree[v] ++;
        }
        vector <pair <ll , ll>> v;
        ans = 0;
        if(r >= l) {
            ans = n * l;
            cout << ans << endl;
        }
        else{
            for(ll i = 1 ; i <= n ; i++) {
                v.push_back(make_pair(i , degree[i]));
            }
            sort(v.begin() , v.end() , sortBySec);

            lib = 0 , road = 0;
            for(auto i : v) {
                if(!visited[i.first]) {
                    bfs(i.first);
                    lib ++;
                }
            }
            ans = l * lib + r * road;
            cout << ans << endl;
        }

        for(ll i = 1 ; i <= n ; i++) {
            graph[i].clear();
        }
    }
    return 0;
}
