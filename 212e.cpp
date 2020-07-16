#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[5001];
ll degree[5001] = {0};
ll level[5001] = {0};
ll visited[5001] = {0};
ll cnt[5001] = {0};

void bfs(ll start) {
    level[start] = 1;
    visited[start] = 1;
    queue <ll> q;
    q.emplace(start);
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(auto i : graph[cur]) {
            if(!visited[i]) {
                level[i] = level[cur] + 1;
                visited[i] = 1;
                q.emplace(i);
            }
        }
    }
 }

int main() {
    ll n;
    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i ++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    ll root = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(degree[i] == 1) {
            root = i;
            break;
        }
    }

    bfs(root);
    ll mxLevel = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cnt[level[i]] ++;
        mxLevel = max(mxLevel , level[i]);
    }

    ll dp[mxLevel] = {0};
    for(ll i = 1 ; i <= mxLevel ; i++) {
        dp[i] = dp[i - 1] + cnt[i];
    }

    ll sum = n - 1;

    set <pair <ll , ll> > s;
    for(ll i = 2 ; i <= mxLevel - 1 ; i++) {
        if(n - cnt[i] == sum) {
            s.insert({dp[i - 1] , sum - dp[i - 1]});
            s.insert({sum - dp[i - 1] , dp[i - 1]});
        }
    }

    cout << s.size() << endl;
    for(auto i : s) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
