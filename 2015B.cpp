#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll msb = 0;
ll l , r;

int main() {
    cin >> l >> r;
    ll rr = log2(r);
    ll lll = log2(l);
    rr ++ , lll ++;

    ll ans = 0;
    for(ll i = rr ; i >= 0 ; i--) {
        if(i - 2 >= 0) {
            ans += (i - 2);
        }
    }
    for(ll i = lll ; i >= 0 ; i--) {
        if(i - 2 >= 0) {
            ans -= (i - 2);
        }
    }

    rr --;
    ll one = 0 , zero = 0;
    for(ll i = 0 ; i <= rr ; i++) {
        ll bit = r & (1ll << i);
        if(bit != 0) {
            one ++;
        }
        else {
            zero ++;
        }
    }

    if(zero == 1) {
        ans ++;
    }
    cout << ans << endl;

    return 0;
}
