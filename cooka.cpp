#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll l , r;
        cin >> l >> r;
        ll bits = 0;
        ll temp = l;

        while(temp) {
            bits ++;
            temp /= 2;
        }

        // ll p = 2 , q = 60;
        // ll sq  = pow(p , q);
        cout << sq - 1 << endl;
        // cout << p << endl;
        ll bitmx = pow(2 , bits) - 1;
        // bitmx %= mod;
        // ll mx = min(bitmx , r);
        ll diff = abs(l - mx);
        diff ++;
        cout << ((diff % mod) * (l % mod))% mod << endl;
    }
}
