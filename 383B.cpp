#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , x;
    cin >> n >> x;
    map <ll , ll> mp;
    ll arr[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    if(x == 0) {
        ll ans = 0;
        for(auto i : mp) {
            ll val = i.second;
            ans += (val * (val - 1)) / 2;
        }
        cout << ans << endl;
    }
    else{
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll xr = arr[i] ^ x;
            if(mp[xr]) {
                ans += mp[xr];
            }
        }

        cout << ans / 2 << endl;
    }
    return 0;
}
