#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main () {
    string a , b;
    cin >> a >> b;
    ll n = a.length();
    vector <ll> dp[n + 1];

    for(ll i = 0 ; i <= n ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            dp[i].push_back(0);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            if(b[i - 1] == a[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1]);
            }
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}
