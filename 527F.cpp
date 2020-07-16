#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
ll arr[200001] = {0};
ll visited[200001] = {0};
vector <ll> graph[200001];
ll sum[200001] = {0};
ll dp[200001] = {0};
ll ans = 0 , total = 0;

void dfs(ll start) {
    visited[start] = 1;
    sum[start] = arr[start];
    dp[start] = 0;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            sum[start] += sum[i];
            dp[start] += dp[i] + sum[i];
        }
    }
}

void dfs2(ll start , ll parent , ll val) {
    ans = max(val , ans);
    visited[start] = 1;
    if(parent != -1) {
        for(auto i : graph[start]) {
            if(!visited[i]) {
                dfs2(i , start , (val - dp[i] - sum[i]) + (total - sum[i]) + dp[i]);
            }
        }
    }
    else{
        for(auto i : graph[start]) {
            if(!visited[i]) {
                dfs2(i , start , (val - dp[i] - sum[i]) + (total - sum[i]) + dp[i]);
            }
        }
    }
}

void input() {
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    for(ll i = 0 ; i < n - 1 ; i ++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void solve() {
    dfs(1);

    memset(visited , 0 , sizeof(visited));
    dfs2(1 , -1 , dp[1]);

    cout << ans << endl;
}

int main() {
    fast_io
    input();
    solve();
    return 0;
}
