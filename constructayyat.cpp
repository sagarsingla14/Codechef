#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll power(ll x, ll y) {
    ll res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;
            res %= mod;
        // y must be even now
        y = y>>1;
        y %= mod;// y = y/2
        x = x*x;
        x %= mod;  // Change x to x^2
    }
    return res % mod;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        ll a = power(m , n);
        a %= mod;
        ll b = power(2 , n - 2) - 1 ;
        b %= mod;

        b *= (m % mod);

        ll res = (a % mod) - (b % mod);
        res %= mod;
        if(res < 0) {
            cout << 0 << endl;
        }
        else {
            cout << (a % mod) - (b % mod) << endl;
        }
    }
}
