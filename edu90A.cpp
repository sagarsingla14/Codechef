#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
        ld a , b , c;
        cin >> a >> b >> c;
        ll bb = b;

        if(a >= c) {
            cout << -1 << " " << bb << endl;
        }
        else{
            ld avg = c / b;
            if(avg >= a) {
                cout << 1 << " " << -1 << endl;
            }
            else{
                cout << 1 << " " << bb << endl;
            }
        }
    }
    return 0;
}
