#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll dp[2001][2001];
int main() {
    ll n , k;
    cin >> n >> k;

    memset(dp , 0 , sizeof(dp));

    for(ll i = 0 ; i < n ; i++) {
        dp[0][i] = 1;
    }
    for(ll i = 0 ; i < k ; i++) {
        dp[i][0] = 1;
    }

    for(ll i = 1 ; i < k ; i++) {
        for(ll j = 1 ; j < n ; j++) {
            dp[i][j] = (dp[i][j - 1] % mod) + (dp[i - 1][j] % mod);
            dp[i][j] %= mod;
        }
    }

    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        ans += dp[k - 1][i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
