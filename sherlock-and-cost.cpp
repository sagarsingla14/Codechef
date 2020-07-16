#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

using namespace std;
int main() {
    train_choot_jayegi

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }

        ll arr[n + 1][2];
        ll dp[n + 1][2];
        memset(arr , 0 , sizeof(arr));
        memset(dp , 0 , sizeof(dp));

        for(ll i = 1 ; i <= n ; i++) {
            arr[i][0] = 1;
            arr[i][1] = a[i];
        }

        for(ll i = 2 ; i <= n ; i++) {
            dp[i][0] = max(dp[i - 1][0] + abs(arr[i][0] - arr[i - 1][0]) , dp[i - 1][1] + abs(arr[i][0] - arr[i - 1][1]));

            dp[i][1] = max(dp[i - 1][1] + abs(arr[i - 1][1] - arr[i][1]) , dp[i - 1][0] + abs(arr[i - 1][0] - arr[i][1]));
        }

        cout << max(dp[n][0] , dp[n][1]) << endl;
    }

    return 0;
}
