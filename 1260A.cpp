#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n,t;
    cin >> t;
    n = t;
    while(t--) {
        ll c , sum ;
        cin >> c >> sum;
        ll val = sum / c;
        ll mod = sum % c;
        ll mul = c - mod;

        ll ans = 0;
        ans += (mul * (val * val));

        ans += (mod * ((val + 1) * (val + 1)));

        cout << ans << endl;
    }
    return 0;
}
