#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll xr(ll x) {
    ll val = x % 8;
    if(val == 0 || val == 1) {
        return x;
    }
    if(val == 2 || val == 3) {
        return 2;
    }
    if(val == 4 || val == 5) {
        return x + 2;
    }
    return 0;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll l , r;
        cin >> l >> r;
        ll ans = xr(r) ^ xr(l - 1);
        cout << ans << endl;
    }
}
