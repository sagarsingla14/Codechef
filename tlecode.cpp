#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll dp[1001][1001];

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        memset(dp , 0 , sizeof(dp));
        memset(arr , 0 , sizeof(arr));

        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);

        ll val;
        cin >> val;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j <= val ; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            dp[i][0] = 0;
        }
        for(ll i = 0 ; i <= val ; i++) {
            if(i % arr[i] == 0) {
                dp[0][i] = i / arr[i];
            }
        }
        for(ll i = 1 ; i < n ; i++) {
            for(ll j = 0 ; j <= val ; j++) {
                if(arr[i] < j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j] , dp[i][j - arr[i]] + 1);
                }
            }
        }
        cout << dp[n - 1][val] << endl;
    }
    return 0;
}
