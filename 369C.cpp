#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m , kk;
ll dp[101][101][101];
ll color[101];
ll cost[101][101];
ll ans = 1e18;

void initializeDp() {
    for(ll i = 0 ; i <= 100 ; i++) {
        for(ll j = 0 ; j <= 100 ; j++) {
            for(ll k = 0 ; k <= 100 ; k++) {
                dp[i][j][k] = 1e18;
            }
        }
    }
    if(color[1] == 0) {
        // if starting tree is not painted then, cost to paint this tree by c[i]th color is cost[i]; i -> color
        for(ll i = 1 ; i <= m ; i++) {
            dp[1][1][i] = cost[1][i];
        }
    }
    else {
        // if starting tree is painted then, no cost to paint this tree by c[i]th color
        dp[1][1][color[1]] = 0;
    }
}

void computeDp() {
    for(ll i = 2 ; i <= n ; i++) {
        for(ll j = 1 ; j <= kk ; j++) {
            if(color[i] == 0) {
                for(ll cur = 1 ; cur <= m ; cur++) {
                    // ith tree is to be painted and painted same as i-1th tree
                    dp[i][j][cur] = min(dp[i][j][cur] , dp[i - 1][j][cur] + cost[i][cur]);
                    for(ll prev = 1 ; prev <= m ; prev++) {
                        if(prev != cur) {
                            // ith tree is to be painted and painted different from i-1th tree
                            dp[i][j][cur] = min(dp[i][j][cur] , dp[i - 1][j - 1][prev] + cost[i][cur]);
                        }
                    }
                }
            }
            else{
                ll cur = color[i];
                // ith tree is already painted and painted same as i-1th tree
                dp[i][j][cur] = min(dp[i][j][cur] , dp[i - 1][j][cur]);
                for(ll prev = 1 ; prev <= m ; prev++) {
                    // ith tree is already painted and painted different from i-1th tree
                    if(prev != cur) {
                        dp[i][j][cur] = min(dp[i][j][cur] , dp[i - 1][j - 1][prev]);
                    }
                }
            }
        }
    }
}


void calcAnswer() {
    for(ll i = 1 ; i <= m ; i++) {
        ans = min(ans , dp[n][kk][i]);
    }

    if(ans == 1e18) {
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}

int main() {
    cin >> n >> m >> kk;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> color[i];
    }
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            cin >> cost[i][j];
        }
    }

    initializeDp();
    computeDp();
    calcAnswer();

    return 0;
}
