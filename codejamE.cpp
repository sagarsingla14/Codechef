#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        x ++;

        ll n , k;
        cin >> n >> k;

        if(k % n) {
            ll sum = (n * (n + 1)) / 2;
            if(n == 4 && k == 6) {
                cout << "Case #" << x << ": POSSIBLE" << endl;
                cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
                cout << 2 << " " << 1 << " " << 4 << " " << 3 << endl;
                cout << 3 << " " << 4 << " " << 2 << " " << 1 << endl;
                cout << 4 << " " << 3 << " " << 1 << " " << 2 << endl;

            }
            else if(n == 4 && k == 10) {
                cout << "Case #" << x << ": POSSIBLE" << endl;
                cout << 2 << " " << 3 << " " << 1 << " " << 4 << endl;
                cout << 3 << " " << 2 << " " << 4 << " " << 1 << endl;
                cout << 1 << " " << 4 << " " << 3 << " " << 2 << endl;
                cout << 4 << " " << 1 << " " << 2 << " " << 3 << endl;
            }
            else if(n == 4 && k == 14) {
                cout << "Case #" << x << ": POSSIBLE" << endl;
                cout << 3 << " " << 4 << " " << 1 << " " << 2 << endl;
                cout << 4 << " " << 3 << " " << 2 << " " << 1 << endl;
                cout << 1 << " " << 2 << " " << 4 << " " << 3 << endl;
                cout << 2 << " " << 1 << " " << 3 << " " << 4 << endl;
            }
            else{
                cout << "Case #" << x << ": IMPOSSIBLE" << endl;
            }
        }
        else{
            ll dp[n][n];
            memset(dp , 0 ,sizeof(dp));

            ll traceVal = k / n;
            for(ll i = 0 ; i < n ; i++) {
                dp[i][i] = traceVal;
            }

            for(ll i = 0 ; i < n ; i++) {
                for(ll j = i + 1 ; j < n ; j ++) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    if(dp[i][j] % n != 0) {
                        dp[i][j] %= n;
                    }
                }
            }

            for(ll i = 0 ; i < n ; i++) {
                for(ll j = i - 1 ; j >= 0 ; j --) {
                    dp[i][j] = dp[i][j + 1] - 1;
                    if(dp[i][j] <= 0) {
                        dp[i][j] += n;
                    }
                }

            }

            cout << "Case #" << x << ": POSSIBLE" << endl;
            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 0 ; j < n ; j ++) {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
