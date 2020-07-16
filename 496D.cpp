#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    string str;
    cin >> str;
    ll ans = 0;
    ll n = str.length();
    ll dp[3] = {0};

    for(ll i = 0 ; i < n ; i++) {
        ll index = (str[i] - '0') % 3;
        if(index == 0) {
            ans ++;
            memset(dp , 0 , sizeof(dp));
        }
        else if((2 * dp[2] + index) % 3 == 0) {
            ans ++;
            memset(dp , 0 , sizeof(dp));
        }
        else if((dp[1] + index) % 3 == 0) {
            ans ++;
            memset(dp , 0 , sizeof(dp));
        }
        else if((2 * dp[2] + dp[1] + index) % 3 == 0) {
            ans ++;
            memset(dp , 0 , sizeof(dp));
        }
        else{
            dp[index] ++;
        }
    }

    cout << ans << endl;
    return 0;
}
