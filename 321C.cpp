#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m;
ll visited[500001];
ll arr[500001];
ll value[500001];
ll degree[500001];

vector <ll> graph[500001];
ll ans;

void dfs(ll start , ll p , ll inherit) {
    visited[start] = 1;
    if(inherit) {
        value[start] = m + 1;
    }
    else if(arr[start]) {
        value[start] ++;
        value[start] += value[p];
        if(value[start] > m) {
            inherit = 1;
        }
    }
    for(auto i : graph[start]) {
        if(!visited[i] && i != p) {
            dfs(i , start , inherit);
        }
    }
}


int main() {
    memset(visited , 0 , sizeof(visited));
    memset(arr , 0 , sizeof(arr));
    memset(degree , 0 , sizeof(degree));
    memset(value , 0 , sizeof(value));


    cin >> n >> m;

    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    dfs(1 , 0 , 0);

    for(ll i = 2 ; i <= n ; i++) {
        if(degree[i] == 1) {
            if(value[i] <= m) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
