// Ispe fata tha
// 10
// 3 8
// 6 2
// 9 7
// 10 1
// 3 5
// 1 3
// 6 7
// 5 4
// 3 6

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , ans;
ll visited[100001];
ll level[100001];
ll degree[100001];

vector <ll> graph[100001];

void dfs(ll parent) {
    visited[parent] = 1;
    for(auto i : graph[parent]) {
        if(!visited[i]) {
            level[i] += level[parent];
            level[i] ++;
            dfs(i);
        }
    }
}

bool isleaf(ll node) {
    if(degree[node] == 1) {
        return true;
    }
    return false;
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));
    memset(level , 0 , sizeof(level));

    cin >> n;

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    level[1] = 1;
    dfs(1);

    set <ll> a , b;
    for(ll i = 1 ; i <= n ; i++) {
        if(level[i] & 1) {
            a.insert(i);
        }
        else{
            b.insert(i);
        }
    }

    ans = 0;
    for(auto i : a) {
        // is loop me fat rha tha !
        if(isleaf(i)) {
            ans += (b.size() - degree[i]);
        }
        else{
            ans += (b.size() - degree[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
