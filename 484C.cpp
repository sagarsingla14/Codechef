#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector <ll> graph[100001];
ll visited[100001];
ll ans , parent;

ll dfs(ll start) {
    ll size = 0;
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            size += dfs(i);
        }
    }
    size ++;
    if(size % 2 == 0) {
        if(start != parent) {
            ans ++;
            size = 0;
        }
    }
    return size;
}

int main() {
    ll n;
    cin >> n;
    memset(visited , 0 , sizeof(visited));
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans = 0;
    parent = 1;
    ll s = dfs(1);
    
    if(s % 2) {
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}
