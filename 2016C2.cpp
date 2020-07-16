#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector <ll> graph[100001];
ll visited[100001;
ll n , m , ans , root;
ll degree[100001];
ll depth[100001];

void dfs(ll start , ll level) {
    visited[start] = 1;
    depth[start] = level;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , depth[start] + 1);
        }
    }
}

void findNewRoot() {
    ll val = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(degree[i] == 1) {
            if(val < depth[i]) {
                val = depth[i];
                root = i;
            }
        }
    }
}

void findAns() {
    for(ll i = 1 ; i <= n ; i++) {
        ans = max(ans , depth[i]);
    }
    ans --;
    cout << ans << endl;
}

int main() {
    fast
    memset(visited , 0 , sizeof(visited));
    memset(depth , 0 , sizeof(depth));
    memset(degree , 0 , sizeof(degree));
    ans = 0;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    root = 1;
    dfs(root , 1);

    findNewRoot();

    memset(visited , 0 , sizeof(visited));
    memset(depth , 0 , sizeof(depth));
    dfs(root , 1);

    findAns();

    return 0;
}
