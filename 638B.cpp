#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll start = n / 2;
        ll a = 0 , b = 0;
        for(ll i = 1 ; i <= start - 1 ; i++) {
            a += (1ll << i);
        }
        a += (1ll << n);
        for(ll i = start ; i <= n - 1 ; i++) {
            b += (1ll << i);
        }
        cout << abs(b - a) << endl;
    }

    return 0;
}
