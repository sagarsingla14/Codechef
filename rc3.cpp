#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        set <ll> s;
        ll arr[n] = {0};
        unordered_map <ll , vector <ll>> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
            mp[arr[i]].push_back(i);
        }

        ll cur = -1;
        ll ans = 1;
        for(auto i : s) {
            ll val = i;
            auto iitr = upper_bound(mp[val].begin() , mp[val].end() , cur);
            auto pos = upper_bound(mp[val].begin() , mp[val].end() , cur) - mp[val].begin();
            if(iitr == mp[val].end()) {
                ans ++;
                cur = -1;
                cur = mp[val][0];
            }
            else{
                cur = mp[val][pos];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
