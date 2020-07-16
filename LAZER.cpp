#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , q;
        cin >> n >> q;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        while (q--) {
            ll l , r , val;
            cin >> l >> r >> val;
            ll ans = 0;
            l-- , r--;
            if(l == r) {
                if(arr[l] == val) {
                    ans = 1;
                }
            }
            for(ll i = l ; i < r ; i++) {
                ll left = arr[i];
                ll right = arr[i + 1];
                if(left > right) {
                    swap(left , right);
                }

                if(val >= left && val <= right) {
                    ans ++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
