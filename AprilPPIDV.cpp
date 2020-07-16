#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector <ll> factor;

ll power(ll x, ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    pw %= mod;
    pw *= pw;
    pw %= mod;
    if(y % 2 == 1) {
        return (pw * x) % mod;
    }
    return pw % mod;
}

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2 ; p * p <= n ; p++) {
        if (prime[p] == true) {
            for (ll i =p * p ; i <= n ; i += p) {
                prime[i] = false;
            }
        }
    }

    for(ll p = 2 ; p <= n ; p++) {
        if(prime[p]) {
            factor.push_back(p);
        }
    }
}


int main() {
    ll t;
    cin >> t;
    SieveOfEratosthenes(1000000);
    while(t--) {
        ll n;
        cin >> n;
        ll sqrtval = sqrt(n);
        ll ans = n % mod;
        for(ll i = 0 ; i < factor.size() ; i++) {
            ll fac = factor[i];

            for(ll pw = 2 ; pw <= 6 ; pw++) {
                ll div = power(fac , pw);
                ll mul = n / div;

                ans += ((mul % mod) * (div % mod));
                ans %= mod;
            }
        }

        ll stop = 0;
        for(ll i = 0 ; i < factor.size() ; i++) {
            for(ll j = i + 1 ; j < factor.size() ; j++) {

            }
        }
        cout << ans % mod << endl;
    }
    return 0;
}
