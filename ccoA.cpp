#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while (t--) {
        ll n , b , m;
        cin >> n >> b >> m;

        ll arr[m] = {0};
        for(ll i = 0 ; i < m ; i++) {
            cin >> arr[i];
        }

        ll prev = arr[0] / b;
        ll ans = 1;

        for(ll i = 1 ; i < m ; i++) {
            ll cur = arr[i] / b;
            if(prev == cur) {
                continue;
            }
            else {
                ans ++;
                prev = cur;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
