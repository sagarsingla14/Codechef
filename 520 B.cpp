#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll spf[1000001] = {0};

void sieve() {
    cout << 1 << endl;
    for(ll i = 0 ; i <= 1000000 ; i++) {
        spf[i] = i;
    }
    for(ll i = 2 ; i <= 1000000 ; i+= 2) {
        spf[i] = 2;
    }

    for(ll i = 3 ; i * i <= 1000000 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    for(ll i = 0 ; i <= 24 ; i++) {
        cout << spf[i] << " ";
    }
    cout << endl;
}

int main() {
    ll n;
    cin >> n;
    sieve();
}
