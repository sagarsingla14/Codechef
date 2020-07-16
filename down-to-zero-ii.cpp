#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll spf[1000001] = {0};

void sieve() {
    for(ll i = 1 ; i <= 1e6 ; i ++) {
        spf[i] = i;
    }

    for(ll i = 2 ; i <= 1e3 ; i ++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 1e6 ; j += i) {
                spf[j] = i;
            }
        }
    }
}

bool isPrime(ll x) {
    if(spf[x] == x) {
        return true;
    }
    return false;
}

int main() {

    sieve();

    ll t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;

        ll ans = 0;
        while(x > 0) {
            if(isPrime(x)) {
                x --;
            }
            else {
                ll root = sqrt(x);
                while(x % root != 0) {
                    root --;
                }
                x = x / root;
            }
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
