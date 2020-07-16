#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll ans = 0;
ll msb = -1;
ll l , r;

void solve() {
    ll xr = l ^ r;
    ll j = 0;
    while(xr) {
        if(xr & 1) {
            msb = j;
        }
        j ++;
        xr >>= 1;
    }
}

int main() {
    train_choot_jayegi

    cin >> l >> r;
    solve();

    for(ll i = 0 ; i <= msb ; i++) {
        ans += (1ll << i);
    }
    cout << ans << endl;
    return 0;
}
