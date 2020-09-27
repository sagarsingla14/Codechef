#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll l , r;
        cin >> l >> r;
        ll left = 2 * l;
        if(left <= r) {
            cout << l << " " << 2 * l << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}
