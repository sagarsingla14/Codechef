#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[200001][2];
ll t , n , a , b;

void makeInf() {
    memset(dp , 0 , sizeof(dp));
    for(ll i = 0 ; i <= n ; i++) {
        for(ll j = 0 ; j < 2 ; j++) {
            dp[i][j] = 1e18;
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        string str;
        cin >> str;
        makeInf();
        dp[0][0] = b;
        for(ll i = 1 ; i <= n ; i++) {
            if(str[i - 1] == '0') {
                dp[i][0] = dp[i - 1][0] + (a + b);
                dp[i][0] = min(dp[i][0] , dp[i - 1][1] + (2 * a) + b);

                dp[i][1] = dp[i - 1][0] + (2 * a + 2 * b);
                dp[i][1] = min(dp[i][1] , dp[i - 1][1] + a + 2 * b);
            }
            else{
                dp[i][1] = dp[i - 1][1] + a + 2 * b;
                if(str[i - 1] != '1') {
                    dp[i][1] = min(dp[i][1] ,  dp[i - 1][0] + 2 * a + 2 * b);
                }
            }
        }

        cout << dp[n][0] << endl;
    }
    return 0;
}
