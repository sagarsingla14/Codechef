#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[9][9];

void test() {
    // cout << dp[0][0];
    for(ll i = 0 ; i < 9 ; i++) {
        // cout << dp[0][i];
        ll x = 1;
    }

}

void printAns() {
    for(ll i = 1 ; i <= 9 ; i++) {
        for(ll j = 1 ; j <= 9 ; j++) {
            cout << dp[i - 1][j - 1];
        }
        cout << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        memset(dp , 0 , sizeof(dp));
        string s;
        ll l = 0 , r = 0;
        for(ll i = 0 ; i < 9 ; i++) {
            cin >> s;
            for(ll j = 0 ; j < 9 ; j ++) {
                ll val = s[j] - '0';
                dp[i][j] = val;
            }
        }

        for(ll i = 0 ; i < 9 ; i++) {
            // cout << "L R " << l << " " << r << en;
            if(dp[l][r] != 1) {
                dp[l][r] = 1;
            }
            else {
                dp[l][r] = 2;
            }
            r += 3 , l++;
            test();
            if(r > 8) {
                r %= 8;
            }
            else{
                continue;
            }
        }
        printAns();
    }
    return 0;
}
