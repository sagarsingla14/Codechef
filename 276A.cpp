#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll t , l , r;
ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

ll F(ll a , ll b) {
    if(a == b) {
        return a;
    }

    ll pw = log2(b);
    if(power(2 , pw) <= a) {
        return F(a - power(2 , pw) , b - power(2 , pw)) + power(2 , pw);
    }
    else if(power(2 , pw + 1) - 1 <= b) {
        return power(2 , pw + 1) - 1;
    }
    else {
        return power(2 , pw) - 1;
    }
}

void solve() {
    ll ans = F(l , r);
    cout << ans << endl;
}

int main() {
    cin >> t;
    while(t--) {
        ll x , y;
        cin >> x >> y >> l >> r;
        solve();
    }
    return 0;
}
