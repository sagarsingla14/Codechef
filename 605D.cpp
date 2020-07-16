#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n + 2] = {0};
    ll dp[n + 2] = {0};
    dp[0] = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    arr[0] = 0;
    dp[n + 1] = 0;
    arr[n + 1] = 0;

    ll mx = 1;
    for(ll i = 2 ; i <= n ; i++) {
        if(arr[i] > arr[i - 1]) {
            dp[i] += dp[i - 1];
        }
    }
    for(ll i = n - 1 ; i >= 1 ; i--) {
        if(dp[i] != 1 && dp[i + 1] != 1) {
            dp[i] = dp[i + 1];
        }
    }

    for(ll i = 2 ; i <= n; i++){
        ll beforeJoint = 0;
        ll afterJoint = 0;
        if(dp[i] == 1) {
            if(arr[i - 1] < arr[i + 1] && i <= n - 1) {
                afterJoint = dp[i - 1] - 1 + dp[i + 1];
            }
            else if(arr[i - 2] < arr[i]){
                beforeJoint = dp[i - 2] - 1 + dp[i + 1];
            }

            mx = max(mx , beforeJoint);
            mx = max(mx , afterJoint);
        }
    }
    for(ll i = 0 ; i <= n ; i++) {
        mx = max(mx , dp[i]);
    }
    cout << mx << endl;
    return 0;
}
