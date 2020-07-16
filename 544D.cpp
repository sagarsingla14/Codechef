#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

int main() {
    ll n;
    cin >> n;
    map <ld , ll> mp;
    ld a[n] = {0};
    ld b[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    for(ll i = 0 ; i < n ; i++) {
        if(a[i] != 0.0) {
            ld d = ((-1.0 * b[i]) / a[i]);
            mp[d] ++;
        }
    }

    ll z = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(a[i] == b[i] && a[i] == 0.0) {
            z ++;
        }
    }

    ll ans = 0;
    for(auto i : mp) {
        ans = max(ans , i.second);
    }
    ans += z;
    cout << ans << endl;
    return 0;
}
