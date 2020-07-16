#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , q;
        cin >> n >> q;
        string str;
        cin >> str;

        ll dp[26][n + 1];
        memset(dp , 0 , sizeof(dp));

        for(ll i = 1 ; i <= n ; i++) {
            dp[str[i - 1] - 'a'][i] ++;
        }

        for(ll i = 0 ; i < 26 ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                dp[i][j] += dp[i][j - 1];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        while(q--) {
            char s , ch;
            ll k;
            cin >> s >> ch >> k;
            if(s == 'L') {
                //  Uppper bound
                auto upans = upper_bound(dp[ch - 'a'] , dp[ch - 'a'] + n + 1 , k) - dp[ch - 'a'];
                cout << upans - 1 << endl;
            }
            else{
                // Lower Bound
                auto lowans = lower_bound(dp[ch - 'a'] , dp[ch - 'a'] + n + 1 , k) - dp[ch - 'a'];
                cout << lowans << endl;
            }
        }
    }
    return 0;
}
