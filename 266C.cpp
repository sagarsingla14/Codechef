#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    ll sum = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(n == 1 || n == 2) {
        cout << 0 << endl;
    }
    else if(sum % 3 != 0) {
        cout << 0 << endl;
    }
    else{
        ll s = sum / 3;
        ll fwd[n + 1] = {0};
        ll dp[n + 1] = {0};
        sum = 0;
        for(ll i = 1 ; i <= n ; i++) {
            sum += arr[i];
            if(sum == s) {
                fwd[i] = 1;
            }
            else{
                fwd[i] = 0;
            }
        }

        sum = 0;
        for(ll i = n ; i >= 1 ; i--) {
            sum += arr[i];
            if(s == sum) {
                dp[i] = 1;
            }
            else{
                dp[i] = 0;
            }
        }
        for(ll i = n - 1 ; i >= 1 ; i--) {
            dp[i] += dp[i + 1];
        }

        ll ans = 0;
        for(ll i = 1 ; i <= n - 2 ; i ++) {
            if(fwd[i]) {
                ans += dp[i + 2];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
