#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1ll;
    while(y) {
        if (y & 1) {
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
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i = 11 ; i >= 0 ; i--) {
            ll pw = power(2 , i);
            ll cnt = n / pw;

            ans += cnt;
            n -= pw * cnt;
            if(n <= 0) {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
