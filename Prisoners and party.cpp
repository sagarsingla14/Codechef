#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n,q;
        cin >> n >> q;
        ll arr[n] = {0};

        for (ll i = 0 ; i < n; i++) {
            cin >> arr[i];
        }
        ll xr[n] = {0};
        xr[n - 1] = arr[n - 1];
        for(ll i = n-2 ; i >= 0 ; i--) {
            xr[i] = xr[i + 1] ^ arr[i];
        }

        ll query[n] = {0};
        for(ll i = 0; i < q; i++) {
            ll index;
            cin >> index;
            query[index - 1] = 1;
        }

        ll ans = 0 , val = 0;
        for(ll i = 0; i < n ; i++){
            if( query[i] ) {
                val = max(val , xr[i]);
            }

            if(val > xr[i]) {
                ans += arr[i];
                xr[i] = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
