#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> graph[100001];
ll visited[100001] = {0};
ll n , m;
ll p[100001] = {0};
ll h[100001] = {0};
ll dp[100001] = {0};
ll ok = 0;

void dfs(ll start) {
    visited[start] = 1;
    dp[start] = p[start];
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            dp[start] += dp[i];
        }
    }
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        for(ll i = 1 ; i <= n ; i++) {
            cin >> p[i];
        }
        for(ll i = 1 ; i <= n ; i++) {
            cin >> h[i];
        }

        for(ll i = 0 ; i < n - 1 ; i++) {
            ll u , v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        ok = 1;
        dfs(1);

        if(n != 1) {
            ll sum = 0;
            for(ll i = 2 ; i <= n ; i++) {
                if(h[i] <= 0) {
                    sum += h[i];
                }
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            if((dp[i] % 2) != abs(h[i] % 2)) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(ll i = 1 ; i <= n ; i++) {
                ll left = -dp[i];
                ll right = dp[i];
                if(left <= h[i] && right >= h[i]) {
                    continue;
                }
                else{
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }

        for(ll i = 1 ; i <= n ; i++) {
            graph[i].clear();
            visited[i] = 0;
            p[i] = 0;
            h[i] = 0;
            dp[i] = 0;
        }

    }
    return 0;
}
