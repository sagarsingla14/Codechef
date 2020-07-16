#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        string str;
        cin >> str;
        ll ans = 0;
        ll n = str.length();
        ll dp[3] = {0};

        for(ll i = 0 ; i < n ; i++) {
            ll index = (str[i] - '0') % 3;
            if(index == 1) {
                if(dp[2] >= 1 || dp[1] >= 2) {
                    ans ++;
                    memset(dp , 0 , sizeof(dp));
                }
                else{
                    dp[index] ++;
                }
                continue;
            }
            if(index == 2){
                if(dp[1] >= 1 || dp[2] >= 2) {
                    ans ++;
                    memset(dp , 0 , sizeof(dp));
                }
                else{
                    dp[index] ++;
                }
                continue;
            }
            else{
                ans ++;
                memset(dp , 0 , sizeof(dp));
            }
        }

        cout << ans << endl;
    }
    return 0;
}
