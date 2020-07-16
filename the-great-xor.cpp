#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x , ll y) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
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
        ll cnt = 0;
        while(n) {
            if(!(n & 1)) {
                ans += power(2 , cnt);
            }
            cnt ++;
            n >>= 1;
        }

        cout << ans << endl;

    }

}
