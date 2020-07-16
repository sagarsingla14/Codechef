#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , m;
vector <ll> graph[200001];
ll visited[200001] = {0};
ll parent[200001] = {0};
ll vistime[200001] = {0};
ll lowtime[200001] = {0};

ll ok = 1;
ll tme = 0;

void dfs(ll root) {
    visited[root] = 1;
    for(auto i : graph[root]) {
        if(visited[i] == 0) {
            parent[i] = root;
            cout << root << " " << i << endl;
            dfs(i);
        }
        else{
            if(visited[i] == 1 && parent[root] != i) {
                cout << root << " " << i << endl;
            }
        }
    }
    visited[root] = 2;
}

void findBridge(ll root) {
    tme ++;
    vistime[root] = tme;
    lowtime[root] = tme;

    for(auto i : graph[root]) {
        if(vistime[i] == 0) {
            parent[i] = root;
            findBridge(i);
            if(lowtime[i] > vistime[root]) {
                ok = 0;
            }
            lowtime[root] = min(lowtime[i] , lowtime[root]);
        }
        else if(i != parent[root]) {
            lowtime[root] = min(vistime[i] , lowtime[root]);
        }
    }
}

int main() {
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i ++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ok = 1;
    findBridge(1);

    if(ok) {
        memset(visited , 0 , sizeof(visited));
        memset(parent , 0 , sizeof(parent));
        dfs(1);
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
