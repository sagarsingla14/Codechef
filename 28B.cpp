#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353
vector <ll> graph[1000];
ll checked;
ll visited[1000];

void dfs(ll u , ll v) {
    visited[u] = 1;
    if(u == v) {
        checked = 1;
    }
    for(auto i : graph[u]) {
        if(!visited[i]) {
            dfs(i , v);
        }
    }
}


int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    ll d[n + 1] = {0};
    for(ll i = 1; i <= n ; i ++){
        cin >> arr[i];
    }
    for(ll i = 1; i <= n ; i ++){
        cin >> d[i];
    }
    for(ll i = 1 ; i <= n ; i ++) {
        ll fwd = i + d[i];
        ll bwd = i - d[i];
        if(fwd <= n) {
            graph[i].push_back(fwd);
            graph[fwd].push_back(i);

        }
        if(bwd >= 1) {
            graph[i].push_back(bwd);
            graph[bwd].push_back(i);
        }
    }
    ll ans = 1;
    for(ll i = 1 ; i <= n ; i++) {
        ll u = i , v = arr[i];
        if(u != v) {
            memset(visited , 0 , sizeof(visited));
            checked = 0;
            dfs(u , v);
            ans &= checked;
        }
    }
    if(ans) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
