#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[4001][4];
ll n , a , b , c , mn;
ll arr[4];

int main() {
    memset(dp , 0 , sizeof(dp));
    memset(arr , 0 , sizeof(arr));

    cin >> n >> arr[0] >> arr[1] >> arr[2];

    sort(arr , arr + 4);
    mn = arr[1];
    dp[arr[1]][1] = 1;
    dp[arr[2]][2] = 1;
    dp[arr[3]][3] = 1;

    for(ll i = mn ; i <= n ; i ++) {
        for(ll cur = 1 ; cur <= 3 ; cur ++) {
            for(ll prev = 1 ; prev <= 3 ; prev ++) {
                if(i - arr[cur] >= 0) {
                    ll val = dp[i - arr[cur]][prev] + 1;
                    if(val != 1) {
                        dp[i][cur] = max(dp[i][cur] , val);
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 1 ; i <= 3 ; i++) {
        ans = max(ans , dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
