#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n;
    cin >> n;

    vector <ll> mp(1e6 + 1, 0);
    vector <ll> dp(1e6 + 1, 0);

    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        mp[x] = 1;
    }

    for(ll i = 1e6 ; i >= 1 ; i--) {
        if(mp[i]) {
            for(ll j = i ; j <= 1e6 ; j += i) {
                if(mp[j]) {
                    dp[i] = max(dp[j] + 1 , dp[i]);
                }
            }
        }
    }

    ll ans = 0;
    for(auto i : dp) {
        ans = max(ans , i);
    }

    cout << ans << endl;

    return 0;
}
