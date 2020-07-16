#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[100001] = {0};
map <ll , ll> mark;
vector <ll> graph[100001];
ll visited[100001] = {0};

void dfs(ll start) {
    visited[start] = 1;

    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            dp[start] += dp[i];
        }
    }
    if(mark[start]) {
        dp[start] ++;
    }
    return;
}


int main() {
    ll n;
    cin >> n;

    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v , t;
        cin >> u >> v >> t;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(t == 2) {
            mark[u] = 1;
            mark[v] = 1;
        }
    }
    dfs(1);

    vector <ll> ans;

    ll cnt = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(dp[i] == 1) {
            ans.push_back(i);
            cnt ++;
        }
    }

    cout << cnt << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;


}
