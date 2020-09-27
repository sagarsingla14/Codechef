#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);ens

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

        ll ans = 0;
        for(ll i = 0 ; i < n - 1 ; i++) {
            for(ll j = i + 1 ; j < n ; j ++) {
                ll cur = arr[i] & arr[j];
                if(cur == arr[i]) {
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}
