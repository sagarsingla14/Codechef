#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll flag = 0;
        for(ll i = 1 ; i < 32 ; i++) {
            ll num = (1ll << i);
            if(num == n) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << -1 << endl;
        }
        else {
            ll ans = 0;
            for(ll i = 0 ; i < 32 ; i ++) {
                ll a = power(2ll , i);
                if(a <= n) {
                    ll terms = (n - a) / (2 * a) + 1;
                    ans += a * terms;
                }
            }
            ans --;
            cout << ans << endl;
        }
    }
    return 0;
}
