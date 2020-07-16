#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
ll dp[1001][2];

int main() {
    ll n , k , d;
    cin >> n >> k >> d;
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(ll i = 1 ; i <= n; i++) {
        for(ll j = 1 ; j <= k ; j++) {
            if(j > i) {
                break;
            }
            else if(j >= d) {
                dp[i][1] += (dp[i - j][1] + dp[i - j][0]);
                dp[i][1] %= mod;
            }
            else{
                dp[i][0] += (dp[i - j][0]);
                dp[i][0] %= mod;
                dp[i][1] += (dp[i - j][1]);
                dp[i][1] %= mod;
            }
        }
    }

    cout << dp[n][1] % mod << endl;
    return 0;
}
