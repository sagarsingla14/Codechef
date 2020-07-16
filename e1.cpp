#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        ll dp[26][n + 1];
        memset(dp , 0 , sizeof(dp));

        for(ll i = 1 ; i <= n ; i++) {
            dp[arr[i] - 1][i] ++;
        }

        for(ll i = 0 ; i < 26 ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                dp[i][j] += dp[i][j - 1];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        // cout << dp[25][0] << " " << dp[25][1] << endl;
        ll mx = 1;

        for(ll i = 0 ; i < 26 ; i++) {
            mx = max(mx , dp[i][n]);
        }
        // cout << mx << endl;
        for(ll i = 0 ; i < 26 ; i++) {
            for(ll j = 0 ; j < 26 ; j++) {
                if(i != j) {
                    // will run in i
                    ll start = 0 , end = n;
                    for(ll z = 1 ; z <= n ; z++) {
                        if(dp[i][z] == 1) {
                            start = z;
                            break;
                        }
                    }
                    if(start == 0 || start == n) {
                        break;
                    }
                    else {
                        // they will run in J..
                        ll p1;
                        p1 = start + 1;
                        for(ll a = p1 ; a < n ; a ++) {
                            for(ll b = a ; b < n ; b ++) {
                                ll cd = 0;
                                ll fd = 0;
                                ll bd = 0;

                                cd = abs(dp[j][b] - dp[j][a - 1]);
                                fd = abs(dp[i][a - 1] - dp[i][start - 1]);
                                bd = abs(dp[i][end] - dp[i][b]);
                                if(fd == bd) {
                                    mx = max(mx , fd + bd + cd);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}
