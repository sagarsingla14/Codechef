#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n , q , c , ans;
ll dp[11][101][101];

void computeDp() {
    for(ll i = 0 ; i <= 10 ; i++) {
        for(ll j = 0 ; j <= 100 ; j ++) {
            for(ll k = 1 ; k <= 100 ; k ++) {
                dp[i][j][k] += dp[i][j][k - 1];
            }
        }
    }

    for(ll i = 0 ; i <= 10 ; i++) {
        for(ll j = 1 ; j <= 100 ; j ++) {
            for(ll k = 0 ; k <= 100 ; k ++) {
                dp[i][j][k] += dp[i][j - 1][k];
            }
        }
    }
}

void solve (ll t , ll x1 , ll y1 , ll x2 , ll y2) {
    for(ll i = 0 ; i <= c ; i++) {
        ll stars = dp[i][x2][y2] - dp[i][x1 - 1][y2] - dp[i][x2][y1 - 1] + dp[i][x1 - 1][y1 - 1];
        ans += (((t + i) % (c + 1)) * stars);
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> q >> c;
    memset(dp , 0 , sizeof(dp));
    ans = 0;

    for(ll i = 0 ; i < n ; i++) {
        ll b , x , y;
        cin >> x >> y >> b;
        dp[b][x][y] ++;
    }

    computeDp();

    while(q--) {
        ans = 0;
        ll t , x1 , x2 , y1 , y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        solve(t , x1 , y1 , x2 , y2);
    }
    return 0;

}
