#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> graph[401];
ll visited[401] = {0};
ll n , m;
map <pair <ll , ll> , ll> mp;
ll dp[401] = {0};

void bfs(ll start) {
    queue <ll> q;
    q.emplace(start);
    visited[start] = 1;
    dp[start] = 0;
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(auto i : graph[cur]) {
            if(!visited[i]) {
                dp[i] = dp[cur] + 1;
                visited[i] = 1;
                q.emplace(i);
            }
            else{
                dp[i] = min(dp[i] , dp[cur] + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    ll train = 0;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        if((u == 1 && v == n) || (u == n && v == 1)) {
            train = 1;
        }
        mp[{u , v}] = 1;
        mp[{v , u}] = 1;
    }

    if(!train) {
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                if(i != j) {
                    if(mp[{i , j}]) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        bfs(1);
        if(visited[n]) {
            cout << dp[n] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                if(i != j) {
                    if(!mp[{i , j}]) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        bfs(1);
        if(visited[n]) {
            cout << dp[n] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
