#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

ll spf[1000001] = {0};
vector <ll> v;

void sieve() {
    for(ll i = 0 ; i <= 1000000 ; i ++) {
        spf[i] = i;
    }
    for(ll i = 2 ; i * i <= 1000000 ; i ++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    for(ll i = 2 ; i <= 1000000 ; i++) {
        if(spf[i] == i) {
            v.push_back(i);
        }
    }
}

int main() {
    fast_io
    sieve();

    ll t;

    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1) {
            cout << 0 << endl;
        }
        else if(n == 2) {
            cout << 1 << endl;
        }
        else {
            auto x = upper_bound(v.begin() , v.end() , n) - v.begin();
            cout << "x " << x << endl;
            cout << n + x - 3 << endl;
        }
    }
    return 0;
}
