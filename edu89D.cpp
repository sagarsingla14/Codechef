#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll spf[10000001];

void precalc() {
    for(ll i = 0 ; i <= 1e7 ; i++) {
        spf[i] = i;
    }

    for(ll i = 2 ; i * i <= 10000000 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 10000000 ; j += i) {
                spf[j] = i;
            }
        }
    }
}

vector <ll> calc(ll val) {
    vector <ll> v;
    while(val > 1) {
        ll x = spf[val];
        while(val % x == 0) {
            val /= x;
            v.push_back(val);
        }
        v.push_back(x);
    }

    return v;
}

int main() {
    precalc();
    ll n;
    cin >> n;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll a[n] = {0};
    ll b[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        vector <ll> fac = calc(arr[i]);

        ll aVal , bVal;
        ll sze = fac.size();

        ll flag = 0;
        for(ll j = 0 ; j < sze ; j ++) {
            for(ll k = j ; k < sze ; k ++) {
                if(fac[j] != 1 && fac[k] != 1) {
                    ll g = __gcd(arr[i] , fac[j] + fac[k]);
                    if(g == 1) {
                        flag = 1;
                        aVal = fac[k];
                        bVal = fac[j];
                        break;
                    }
                }
            }
            if(flag) {
                break;
            }
        }

        if(flag) {
            a[i] = aVal;
            b[i] = bVal;
        }
        else {
            a[i] = -1;
            b[i] = -1;
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for(ll i = 0 ; i < n ; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
