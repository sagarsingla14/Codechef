#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a , ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
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
        if(n == 1) {
            cout << 0 << endl;
        }
        else{
            ll num = n;
            ll mul = n / 2;
            while(num > 1) {
                ans += mul * num;
                num -= 2;
                mul --;
            }
            ans *= 4;
            ll x = n / 2;
            ll sub = (x * (x + 1)) / 2;
            sub *= 4;
            cout << ans - sub << endl;
        }
    }
    return 0;
}
