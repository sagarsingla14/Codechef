#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll msb = log2(x);
        msb ++;
        msb = (1ll << msb) - 1;
        if(msb == x) {
            ll ans = 0;
            ll prime = 1;
            for(ll i = 2 ; i <= sqrt(x) ; i++) {
                if(x % i == 0) {
                    ll f1 = i;
                    ll f2 = x / i;
                    prime = 0;
                    ll val = max(f1 , f2);
                    ans = max(ans , val);
                }
            }
            if(prime) {
                cout << 1 << endl;
            }
            else {
                cout << ans << endl;
            }
        }
        else{
            cout << msb << endl;
        }
    }
    return 0;
}
