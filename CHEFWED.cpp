#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[1001][1001];
ll sum[101][1001];
ll arr[1001][1001][101];

int main() {
    fast_io
    ll t;
    cin >> t;
    for(ll i = 0 ; i < t ; i++) {
        ll n , k;
        cin >> n >> k;

        memset(dp , 0 , sizeof(dp));
        memset(sum , 0 , sizeof(sum));

        for(ll i = 1 ; i <= n ; i++) {
            ll x; cin >> x;
            sum[x][i] ++;
        }

        for(ll i = 1 ; i <= 100 ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }

        ll mx = 0;
        for(ll i = 1 ; i <= 100 ; i++) {
            mx = max(mx , sum[i][n]);
        }

        // if(k == 1) {
        //     cout << mx << endl;
        //     continue;
        // }

        for(ll i = 1 ; i <= n ; i++) {
            dp[i][1] = k;
        }

        for(ll j = 2 ; j <= n ; j++) {
            for(ll i = 1 ; i <= n - j + 1 ; i++) {
                dp[i][j] = min(dp[i][j - 1] , dp[i + 1][j - 1]);
                ll cnt = 0;
                for(ll z = 1 ; z <= 100 ; z++) {
                    ll add = (sum[z][i + j - 1] - sum[z][i - 1]);
                    if(add > 1) {
                        cnt += add;
                    }
                }
                dp[i][j] = min(dp[i][j] , k + cnt);
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
