#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m;
ll visited[500001];
ll arr[500001];
ll value[500001];
ll degree[500001];
map <pair <ll , ll> , ll> mp;
vector <ll> graph[500001];
ll sum = 0;

ll dfs(ll start , ll parent) {
    visited[start] = 1;
    if(degree[start] == 0) {
        return mp[{start , parent}];
    }
    ll val = 0;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            val = max(val , dfs(i , start));
        }
    }
    return val + mp[{start , parent}];
}

void subtractDegree() {
    for(ll i = 1 ; i <= n - 1 ; i++) {
        degree[i] --;
    }
}


int main() {
    memset(visited , 0 , sizeof(visited));
    memset(arr , 0 , sizeof(arr));
    memset(degree , 0 , sizeof(degree));

    cin >> n;

    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;

        mp[{u , v}] = w;
        mp[{v , u}] = w;
    }

    subtractDegree();

    ll ans = dfs(0 , 0);

    cout << ans << endl;
    return 0;
}
