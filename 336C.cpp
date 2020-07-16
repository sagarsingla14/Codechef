#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    fast_io
    ll n;
    cin >> n;
    map <ll , ll> mp;
    map <ll , ll> dp;

    ll mx = 0;

    for(ll i = 0 ; i < n ; i++) {
        ll x , p;
        cin >> x >> p;
        mp[x] = p;
        mx = max(mx , x);
    }

    for(ll i = 0 ; i <= mx ; i ++) {
        if(mp[i]) {
            dp[i] = dp[i - mp[i] - 1] + 1;
        }
        else{
            dp[i] = dp[i - 1];
        }
    }

    ll ans = 0;
    for(ll i = 0 ; i <= mx ; i ++) {
        ans = max(ans , dp[i]);
    }
    ans = n - ans;
    cout << ans << endl;

    return 0;
}
