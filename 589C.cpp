#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll unsigned long long int
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

set <ll> primes;
void calcPrime(ll x) {
    while(x % 2 == 0) {
        x /= 2;
        primes.insert(2);
    }
    for(ll i = 3 ; i <= sqrt(x) ; i++) {
        while(x % i == 0) {
            x /= i;
            primes.insert(i);
        }
    }
    if(x > 1) {
        primes.insert(x);
    }
}


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

ll powerMod(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return res % mod;
}

int main() {
    fast_io
    ll x , n;
    cin >> x >> n;
    calcPrime(x);

    map <ll , ll> mp;
    for(auto i : primes) {
        ll cnt = 1;
        while(1) {
            ll pw = power(i , cnt);
            ll add = n / pw;
            mp[i] += add;
            if(add == 1 || add / i == 0) {
                break;
            }
            cnt ++;
        }
    }

    ll ans = 1;
    for(auto i : primes) {
        if(mp[i])  {
            ans *= powerMod(i , mp[i]);
            ans %= mod;
        }
    }
    cout << ans % mod << endl;
    return 0;
}
