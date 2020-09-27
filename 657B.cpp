#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    ll t;
    cin >> t;
    while(t--) {
        ll l , r , m;
        cin >> l >> r >> m;
        ll a = -1 , b = -1 , c = -1 , diff = -1;
        ll found = 0;
        for(ll i = l ; i <= r ; i++) {
            ll left = 1 , right = 10000000000;
            while(left <= right) {
                ll mid = (left + right) >> 1ll;
                ll val = m - (i * mid);

                if(val >= (l - r) && val <= (r - l)) {
                    found = 1;
                    a = i;
                    diff = val;
                    break;
                }
                else{
                    if(val < (l - r)) {
                        right = mid - 1;
                    }
                    else if(val > (r - l)) {
                        left = mid + 1;
                    }
                }
            }
            if(found) {
                break;
            }
        }
        if(diff > 0) {
            b = r;
            c = b - diff;
        }
        else{
            b = l;
            c = b - diff;
        }

        cout << a << " " << b << " " << c << endl; 
    }
    return 0;
}
