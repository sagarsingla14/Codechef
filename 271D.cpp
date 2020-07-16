#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll ans = 0;
ll dp[100001][2];
ll t , k , a , b;
ll sum[100001];
// 1859 48096
// 75634 80941
// 27808 89615
// 58867 93494

void fillDP() {
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(ll i = 1 ; i < k ; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    dp[k][0] = 1;
    dp[k][1] = 1;
    for(ll i = k + 1 ; i <= 1e5 ; i++) {
        dp[i][1] = dp[i - 1][0] % mod + dp[i - 1][1] % mod;
        dp[i][0] = dp[i - k][0] % mod + dp[i - k][1] % mod;
        dp[i][1] %= mod;
        dp[i][0] %= mod;
    }

    for(ll i = 1 ; i <= 1e5 ; i++) {
        sum[i] += (sum[i - 1] % mod) + (dp[i][0] + dp[i][1]) % mod;
        sum[i] %= mod;
    }
}

void solve() {
    ans = sum[b] - sum[a - 1] + mod;
}



int main() {
    cin >> t >> k;

    memset(dp , 0 , sizeof(dp));
    memset(sum , 0 , sizeof(sum));

    fillDP();

    while(t--) {
        ans = 0;
        cin >> a >> b;
        solve();
        cout << ans % mod << endl;
    }
    return 0;
}
