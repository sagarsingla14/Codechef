#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

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

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll two = 0 , three = 0;
        ll x = n;
        while(x % 2 == 0) {
            two ++;
            x /= 2;
        }
        while(x % 3 == 0) {
            three ++;
            x /= 3;
        }

        if(x > 1) {
            cout << -1 << endl;
        }
        else{
            if(two > three) {
                cout << -1 << endl;
            }
            else{
                ll ans = abs(two - three) + three;
                cout << ans << endl;
            }
        }
    }
    return 0;
}
