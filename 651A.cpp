#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << n / 2 << endl;
    }
    return 0;
}
