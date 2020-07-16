#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll dp[n][n] , val[n][n];

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            if(i == j) {
                dp[i][i] = 1;
                val[i][i] = arr[i];
            }
            else{
                dp[i][j] = INT_MAX;
                val[i][j] = INT_MAX;
            }
        }
    }

    for(ll l = 1 ; l < n ; l++) {
        for(ll i = 0 ; i < n - l ; i++) {
            ll end = i + l;
            for(ll j = i ; j < end ; j++) {
                if(dp[i][end] >= dp[i][j] + dp[j + 1][end]) {
                    dp[i][end] = dp[i][j] + dp[j + 1][end];
                    if(dp[i][j] == 1 && dp[j + 1][end] == 1 && val[i][j] == val[j + 1][end]) {
                        dp[i][end] = 1;
                        val[i][end] = val[i][j] + 1;
                    }
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
