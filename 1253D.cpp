#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> g[200001];
bool visited[200001];
ll maxnode = 0;

void dfs(ll start) {
    maxnode = max(maxnode , start);
    visited[start] = true;

    for(auto i = 0; i < g[start].size(); i++) {
        if(!visited[g[start][i]]) {
            dfs(g[start][i]);
        }
    }
}

int main() {
    ll n , m;
    cin >> n >> m;

    memset(visited , false  , sizeof(visited));

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            if(maxnode > i) {
                ans ++;
            }
            dfs(i);
        }
    }

    cout << ans << endl;
    return 0;
}
