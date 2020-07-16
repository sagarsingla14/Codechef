// 2 1 3
// 3

// Crashed
// 3 1 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll n , l ,r ;
    cin >> n >> l >> r ;
    ll val[3] = {0};

    val[0] = r / 3 - ceil(l / 3.0) + 1;
    val[1] = (r - 1) / 3 - ceil((l - 1) / 3.0) + 1;

    // Crash Point
    if(r >= 2) {
        val[2] = (r - 2) / 3 - ceil((l - 2) / 3.0) + 1;
    }
    
    ll dp[n][3];
    memset(dp , 0 , sizeof(dp));

    dp[0][0] = val[0];
    dp[0][1] = val[1];
    dp[0][2] = val[2];

    for(ll i = 1 ; i < n ; i++) {
        for(ll j = 0 ; j < 3 ; j++) {
            for(ll k = 0  ; k < 3 ; k++) {
                dp[i][j] += ((dp[i - 1][k] % mod) * (val[(j - k + 3) % 3] % mod));
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[n - 1][0] << endl;
    return 0;
}
