#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll brr[n] = {0};

        ll mna = 1000000000000;
        ll mnb = 1000000000000;

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mna = min(mna , arr[i]);
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> brr[i];
            mnb = min(mnb , brr[i]);
        }

        ll c[n] = {0};
        ll o[n] = {0};

        for(ll i = 0 ; i < n ; i++) {
            c[i] = arr[i] - mna;
            o[i] = brr[i] - mnb;
        }

        ll ans = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(o[i] && c[i]) {
                ll mn = min(o[i] , c[i]);
                ans += mn;
                o[i] -= mn;
                c[i] -= mn;
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            ans += o[i];
            ans += c[i];
        }

        cout << ans << endl;
    }
    return 0;
}
