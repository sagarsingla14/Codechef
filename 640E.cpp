#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll ok = 0;
ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        ll arr[n + 1] = {0};
        ll mp[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
        }

        ll dp[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i ++) {
            dp[i] = dp[i - 1] + arr[i];
        }

        ll ans = 0;
        for(ll i = 1 ; i < n ; i++) {
            for(ll j = i + 1 ; j <= n ; j++) {
                ok = 0;
                ll sum = dp[j] - dp[i - 1];
                if(sum > n) {
                    break;
                }
                else{
                    if(mp[sum] != 0) {
                        ans += mp[sum];
                        mp[sum] = 0;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
