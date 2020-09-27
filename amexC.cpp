#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check(ll x , ll m , ll n) {
    if(x % 2 == 0) {
        ll nReq = (x / 2) * (x / 2);
        if(nReq <= n) {
            return true;
        }
        else {
            ll diff = nReq - n;
            ll mPresent = m / 4;
            if(mPresent >= diff) {
                return true;
            }
            return false;
        }
    }
    else {
        ll nReq = (x / 2) * (x / 2);
        if(nReq <= n) {
            if(2 * x - 1 <= m) {
                return true;
            }
            else{
                return check(x + 1 , m , n);
            }
        }
        else{
            ll diff = nReq - n;

            ll mPresent = m / 4;
            ll rem = m % 4;

            if(mPresent < diff) {
                return false;
            }
            else {
                mPresent -= diff;
                mPresent *= 4;
                mPresent += rem;

                cout << mPresent << endl;
                if(2 * x - 1 <= mPresent) {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
}

void Solution(ll m , ll n) {
    ll ans = 0;
    ll l = 0 , r = 1000000000;

    while(l <= r) {
        ll mid = (l + r) / 2;

        if(check(mid , m , n)) {
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        Solution(m , n);
    }
    return 0;
}
