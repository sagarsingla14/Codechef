#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
int main() {
    ll n , m;
    cin >> n >> m;
    ll dp[2 * m][n];

    // dp[i][j] represents number of arrays can be formed from ith index to last index
    // when we place j to ith index

    memset(dp , 0 , sizeof(dp));
    ll j = 1;
    for(ll i = n - 1 ; i >= 0 ; i--) {
        dp[2 * m - 1][i] = j;
        j ++;
    }

    for(ll i = 2 * m - 2  ; i >= 0 ; i--) {
        for(j = n - 1 ; j >=0 ; j--) {
            if(j == n - 1) {
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i + 1][j] % mod + dp[i][j + 1] % mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
