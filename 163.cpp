#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <map>
#define mod 1000000007
#define ll long long int
int main() {
    string s , t;
    cin >> s >> t;
    ll ls = s.length();
    ll lt = t.length();
    ll dp[ls + 1][lt + 1] = {0 , 0};
    for(ll i = 1 ; i <= ls ; i++) {
        for(ll j = 1 ; j <= lt ; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i][j - 1] % mod + dp[i - 1][j - 1] % mod + 1;
                dp[i][j] %= mod;
            }
            else{
                dp[i][j] = dp[i][j - 1] % mod;
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for(ll i = 1 ; i <= ls ; i++) {
        ans += (dp[i][lt] % mod);
        ans %= mod;
    }
    cout << ans  % mod << endl;
    return 0;
}
