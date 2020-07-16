#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int main() {
    train_choot_jayegi
    string str;
    cin >> str;
    ll n = str.length();
    ll dp[2][n + 1];
    memset(dp , 0 , sizeof(dp));

    for(ll i = 1 ; i <= n ; i++) {
        dp[str[i - 1] - 'a'][i] = 1;
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 0 ; j < 2 ; j++) {
            dp[j][i] += dp[j][i - 1];
        }
    }

    // for(ll i = 0 ; i < 2 ; i++) {
    //     for(ll j = 0 ; j <= n ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    ll start = 0 , end = n;
    ll s1 = 0, s2 = 0 , s3 = 0;

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = i ; j <= n ; j ++) {
            s1 = abs(dp[0][i - 1] - dp[0][start]);
            s2 = abs(dp[1][j] - dp[1][i - 1]);
            s3 = abs(dp[0][end] - dp[0][j - 1]);
            ans = max(ans , s1 + s2 + s3);
            // cout << "i j s1 s2 s3 sum ans " << i <<" " << j << " " << s1 << " "<< s2 << " " << s3 << " " << s1 + s2 + s3  << " " << ans << endl;
        }
    }

    cout << ans << endl;
    return 0;
}
