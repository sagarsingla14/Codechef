#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n; i++) {
            cin >> arr[i];
        }

        ll ans = 1;

        vector <ll> v;
        for(ll i = 1 ; i < n ; i++) {
            ll price = arr[i];
            for(ll j = i - 1 ;j >= 0 && j >= i - 5 ; j--) {
                v.push_back(arr[j]);
            }
            sort(v.begin() , v.end());
            if(price < v[0]) {
                ans ++;
            }
            v.clear();
        }
        cout << ans << endl;
    }
    return 0;
}
