#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
vector <ll> graph[200001];
ll arr[200001] = {0};
ll visited[200001] = {0};
ll dp[200001] = {0};

void dfs(ll root) {
    visited[root] = 1;
    for(auto i : graph[root]) {
        if(!visited[i]) {
            dfs(i);
            dp[root] += max(0ll , dp[i]);
        }
    }
}

void calcAnsDfs(ll root) {
    visited[root] = 1;
    for(auto i : graph[root]) {
        if(!visited[i]) {
            if(dp[i] >= 0) {
                dp[i] = max(dp[root] , dp[i]);
            }
            else{
                dp[i] = max(dp[i] ,  dp[root] - 1);
            }
            calcAnsDfs(i);
        }
    }
}

int main() {
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        dp[i] = arr[i] ? 1 : -1;
    }

    for(ll i = 0 ; i < n - 1 ; i ++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll root = 1;
    dfs(root);

    memset(visited , 0 , sizeof(visited));

    root = 1;
    calcAnsDfs(root);

    for(ll i = 1 ; i <= n ; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
