#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll dp[n][n];
        ll arr[n][n];

        for(ll i = 0 ; i < n ; i++) {
            string str;
            cin >> str;
            for(ll j = 0 ; j < n ; j ++) {
                if(str[j] == '1') {
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = 0;
                }
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < n ; j ++) {
                dp[i][j] = 0;
            }
        }

        for(ll i = 0 ; i < n ; i ++) {
            if(arr[i][n - 1] == 1) {
                dp[i][n - 1] = 1;
            }
        }
        for(ll i = 0 ; i < n ; i ++) {
            if(arr[n - 1][i] == 1) {
                dp[n - 1][i] = 1;
            }
        }

        ll ans = 1;
        for(ll i = n - 2 ; i >= 0 ; i --) {
            for(ll j = n - 2 ; j >= 0 ; j--) {
                if(dp[i][j] == 0 && arr[i][j] == 1) {
                    dp[i][j] = dp[i + 1][j] | dp[i][j + 1];
                    if(dp[i][j] == 0) {
                        ans = 0;
                        break;
                    }
                }
            }
        }

        if(ans) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
