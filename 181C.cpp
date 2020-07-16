#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll fac[1000001] = {0};
ll a , b , n;
ll ans = 0;

void preCalc() {
    fac[0] = 1;
    for(ll i = 1 ; i <= 1000000 ; i++) {
        fac[i] = (fac[i - 1] % mod) * (i % mod);
        fac[i] %= mod;
    }
}

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= (x % mod);
            res %= mod;
        }
        x *= x % mod;
        x %= mod;
        y >>= 1ll;
    }
    return res % mod;
}

ll inv(ll x) {
    return power(x , mod - 2) % mod;
}

ll check(ll x) {
    ll flag = 1;
    while(x) {
        if(x % 10 != a && x % 10 != b) {
            flag = 0;
            break;
        }
        x /= 10;
    }
    return flag;
}

int main() {
    fast_io
    preCalc();
    cin >> a >> b >> n;

    for(ll i = 0 ; i <= n ; i++) {
        ll sum = a * i + b * (n - i);

        if(check(sum)) {
            ans += ((fac[n] % mod) * inv((fac[n - i] % mod * fac[i] % mod) % mod) % mod) % mod;
        }
    }
    cout << ans % mod << endl;
    return 0;

}
