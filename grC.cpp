#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    ll dp[n + 2][n + 2];
    memset(dp , 0 , sizeof(dp));

    for(ll i = 1 ; i <= n ; i++) {
        dp[i][i] = 1;
        dp[i - 1][i] = 1;
        dp[i + 1][i] = 1;
        dp[i][i - 1] = 1;
        dp[i][i + 1] = 1;
    }

    dp[0][0] = 1;
    dp[n + 1][n + 1] = 1;

    ll cnt = 0;
    for(ll i = 0 ; i <= n + 1 ; i++) {
        for(ll j = 0 ; j <= n + 1 ; j++) {
            if(dp[i][j] == 1) {
                cnt ++;
            }
        }
    }

    cout << cnt << endl;
    for(ll i = 0 ; i <= n + 1 ; i++) {
        for(ll j = 0 ; j <= n + 1 ; j++) {
            if(dp[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
