#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , a , b;
        cin >> n >> m >> a >> b;

        if(n * a == m * b) {
            cout << "YES" << endl;

            ll dp[n][m];
            memset(dp , 0 , sizeof(dp));

            ll shift = 0;

            for(ll i = 1 ; i <= 50 ; i++) {
                if((i * n) % m == 0) {
                    shift = i;
                    break;
                }
            }

            for(ll i = 0 ; i < a ; i++) {
                dp[0][i] = 1;
            }
            for(ll i = 1 ; i < n ; i ++) {
                for(ll j = 0 ; j < m ; j ++) {
                    dp[i][(j + shift) % m] = dp[i - 1][j];
                }
            }

            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 0 ; j < m ; j ++) {
                    cout << dp[i][j];
                }
                cout << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
