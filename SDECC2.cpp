#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll prime(ll n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n%2 == 0 || n%3 == 0) {
        return 0;
    }
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n %( i+2) == 0)
            return 0;
    return 1;
}
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        for(ll i = 0 ; i < 20 ; i++) {
            ll x = 0;
        }
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = i + 1 ; j < n ; j ++) {
                ll val = arr[i];
                val += arr[j];

                if(prime(val) == 1) {
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
