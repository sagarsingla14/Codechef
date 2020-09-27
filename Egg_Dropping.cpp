#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;

        ll dp[n + 1][k + 1];
        memset(dp , 0 , sizeof(dp));

        for(ll i = 1 ; i <= k ; i++) {
            dp[1][i] = i;
        }
        for(ll i = 1 ; i <= n ; i++) {
            dp[i][1] = 1;
        }

        for(ll i = 2 ; i <= k ; i++) {
            for(ll e = 2 ; e <= n ; e++) {
                ll mx = INT_MAX;
                for(ll j = 1 ; j <= i - 1 ; j++) {
                    mx = min(mx , max(dp[e - 1][j - 1] , dp[e][i - j]) + 1);
                }
                dp[e][i] = mx;
            }
        }

        cout << dp[n][k] << endl;
    }
}
