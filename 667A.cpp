#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll a , b;
        cin >> a >> b;
        ll diff = abs(a - b);
        ll ans = 0;
        ans = diff / 10;
        if(diff % 10) {
            ans ++;
        }

        cout << ans << endl;
    }
    return 0;
}
