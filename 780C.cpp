#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

ll ans = 0;
ll n;
vector <ll> graph[500001];
ll visited[500001];
ll color[500001];
ll degree[500001];

void dfs(ll start , ll parent ) {
    visited[start] = 1;
    ll col = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            // Color Assigned before visiting chlid
            while(color[parent] == col || color[start] == col) {
                col ++;
            }
            color[i] = col;
            col ++;
            dfs(i , start);
        }
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(color , 0 , sizeof(color));
    memset(degree , 0 , sizeof(degree));

    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    for(ll i = 1 ; i <= n ; i++) {
        ans = max(ans , degree[i]);
    }

    color[1] = 1;
    dfs(1 , 0);

    cout << ans + 1 << endl;
    for(ll i = 1 ; i <= n ; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
    return 0;
}
