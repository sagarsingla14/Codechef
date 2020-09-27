#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        set <ll> s;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        ll ans = 0;
        map <ll , ll> mp;
        for(auto i : s) {
            ll val = i;
            ll cnt = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(arr[i] == val) {
                    cnt ++;
                    i ++;
                }
            }
            mp[val] = cnt;
        }

        ll mx = 0;
        for(auto i : mp) {
            if(i.second > mx) {
                mx = i.second;
                ans = i.first;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
