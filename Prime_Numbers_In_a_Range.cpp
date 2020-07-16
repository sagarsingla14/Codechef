#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void sieve(ll l , ll r , ll rt , bool isPrime[] , vector <ll> &primes , vector <bool> &primeInrange) {
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 2 ; i <= rt ; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(ll j = i * i ; j <= rt ; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(auto i : primes) {
        for(ll j = max(i * i , ((l + i - 1) / i) * i) ; j <= r ; j += i) {
            primeInrange[j - l] = false;
        }
    }

    if(l == 1) {
        primeInrange[0] = false;
    }
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        ll l , r;
        cin >> l >> r;
        ll rt = sqrtl(r);
        bool isPrime[rt + 1];

        memset(isPrime , true , sizeof(isPrime));
        vector <ll> primes;
        vector <bool> primeInrange(r - l + 1 , true);

        sieve(l , r , rt , isPrime , primes , primeInrange);

        for(ll i = 0 ; i <= (r - l) ; i++) {
            if(primeInrange[i]) {
                cout << (i + l) << endl;
            }
        }
    }
    return 0;
}
