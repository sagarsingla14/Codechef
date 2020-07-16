#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2) % mod;
    pw *= pw;
    if(y & 1) {
        return (pw * x) % mod;
    }
    return pw % mod;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll orr = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            orr |= arr[i];
        }

        ll ans = power(2 , n - 1) % mod;
        ans *= orr;
        cout << ans % mod << endl;
    }
    return 0;
}
