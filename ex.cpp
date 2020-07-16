#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll fun(ll n) {
    if(n == 2) {
        return 1;
    }
    if(n == 3) {
        return 3;
    }
    if(n == 4) {
        return 3;
    }
    if(n == 5) {
        return 5;
    }
    if(n % 2) {
        return n;
    }
    return n - 1;
}

ll power(ll a , ll b) {
    ll p = 1;
    while (b > 0) {
        if (b & 1) {
            p *= a;
            p %= mod;
        }
        b >>= 1;
        b %= mod;
        a *= a;
        a %= mod;
    }
    return p % mod;
}

int main() {
    ll t , l , r;
    cin >> t >> l >> r;
    ll ans = 0;
    for(ll i = 0 ; i <= abs(r - l) ; i++) {
        ll tp = power(t , i);
        tp %= mod;
        ll func = fun(l + i);
        func %= mod;
        ans %= mod;
        ans += ((tp * func) % mod);
        ans %= mod;
        // cout << "pow " << tp << " func " << func << " ans " << ans << endl;
    }
    cout << ans % mod << endl;
    return 0;
}
