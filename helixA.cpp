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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll l = (n * (n + 1)) / 2;
        ll a = (l % mod - n % mod + 1 + mod) % mod;
        ll inv = 500000004 % mod;
        ll ans = (n % mod) * ((a % mod + l % mod)) % mod;
        ans %= mod;

        ans *= inv % mod;
        ans %= mod;

        cout << ans << endl;
    }
    return 0;
}
