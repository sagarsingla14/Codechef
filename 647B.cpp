#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isPrime(ll x) {
    if(x == 2 || x == 3) {
        return true;
    }
    for(ll i = 2 ; i * i <= x ; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

bool check(ll val , ll p , ll n) {
    ll sq = sqrt(val);
    for(ll i = 2 ; i <= min(sq , p) ; i++) {
        if(val % i == 0) {
            ll fac = val / i;

            if(fac <= n) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    fast_io
    ll p , n;
    cin >> p >> n;
    ll mx = (n / p);

    ll flag = 0;
    for(ll i = n ; (i > p && i > 1) ; i--) {
        if(isPrime(i)) {
            flag = i;
            break;
        }
        else {
            if(i % p) {
                bool ok = check(i , p , n);
                if(ok) {
                    flag = i;
                    break;
                }
            }
        }
    }

    if(flag) {
        cout << flag << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
