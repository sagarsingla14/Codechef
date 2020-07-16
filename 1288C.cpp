#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int

int main() {
    ll n, m;
    cin >> n >> m;
    ll dp[2 * m][n + 1];
    for(ll i = 0 ; i < 2 * m ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            dp[i][j] = 0;
        }
    }


    for(ll i = n; i >= 1; i--){
        dp[2 * m - 1][i] = 1;
        if(i != n) {
            dp[2 * m - 1][i] += dp[2 * m - 1][i + 1];
        }
    }

    for(ll i = 0 ; i < 2 * m ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(ll i = 2 * m - 2; i >= 0; i--) {
        for(ll j = 1; j <= n; ++j) {
            dp[i][j] = dp[i + 1][j];
        }

        for(int j = n - 1; j >= 1; j--) {
            dp[i][j] += dp[i][j + 1];
            dp[i][j] %= MOD;
        }
    }

    for(ll i = 0 ; i < 2 * m ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << dp[0][1] << endl;
    return 0;

}
