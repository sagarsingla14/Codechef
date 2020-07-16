#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll spf[10001] = {0};
ll n , k;
vector <ll> primes;

void sieve() {
    for(ll i = 0 ; i <= 10000 ; i++) {
        spf[i] = i;
    }

    for(ll i = 2 ; i * i <= 10000 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 10000 ; j += i) {
                spf[j] = i;
            }
        }
    }

    for(ll i = 2 ; i <= 1000 ; i++) {
        if(spf[i] == i) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    cin >> n >> k;

    ll cnt = 0;
    for(ll i = 1 ; i < primes.size() ; i++) {
        if(primes[i] + primes[i - 1] + 1 <= n) {
            ll sum = primes[i] + primes[i - 1] + 1;

            if(spf[sum] == sum) {
                cnt ++;
            }
        }
    }

    if(cnt >= k) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
