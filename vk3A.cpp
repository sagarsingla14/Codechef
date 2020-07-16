#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll x , y , p , q , ans = 0;

void solve() {
    ll v1 = x / p;
    if(x % p) {
        v1 ++;
    }
    ll v2 = (y - x) / (q - p);
    if((y - x) % (q - p)) {
        v2 ++;
    }

    ll ans = max(v1 , v2);
    ans = ans * q - y;

    cout << ans << endl;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        cin >> x >> y >> p >> q;
        if(p == 0) {
            if(x == 0) {
                cout << 0 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else if(p == q) {
            if(x == y) {
                cout << 0 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            solve();
        }
    }
    return 0;
}
