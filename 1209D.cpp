#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[100001];
ll visited[100001];
ll cnt;

void dfs(ll start) {
    cnt ++;
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ll n , k;
    cin >> n >> k;
    memset(visited , 0 , sizeof(visited));
    for(ll i = 0 ; i < k ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cnt = 0;
        if(!visited[i]) {
            dfs(i);
            ans += (cnt - 1);
        }
    }

    cout << k - ans << endl;
    return 0;
}
