#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;

ll leftpos(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll p = leftpos(10 , y / 2) % mod;
    p %= mod;
    p *= p;
    p %= mod;
    if(y % 2) {
        p *= 10;
    }
    return p % mod;
}

ll n;
int main() {
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {

        if(n == i) {
            cout << 10 << endl;
            break;
        }

        ll corner = 2 * 10 * 9;
        corner *= leftpos(10 , n - i - 1);
        corner %= mod;

        ll middle = (n - i - 1);
        middle *= 10 * 9 * 9;
        middle *= leftpos(10 , n - i - 2);
        middle %= mod;

        cout << (corner + middle) % mod << " ";
    }
    cout << endl;
    return 0;
}
