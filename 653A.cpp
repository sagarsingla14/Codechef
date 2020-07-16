#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

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
        ll x , y , n;

        cin >> x >> y >> n;

        ll val = n / x;
        val *= x;
        if(val + y <= n) {
            cout << val + y << endl;
        }
        else{
            ll ans = val - (x - y);
            cout << ans << endl;
        }
    }
    return 0;
}
