#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n;

int main() {
    fast_io
    cin >> n;

    map <ll , ll> mp;
    vector <ll> v;
    ll arr[n] = {0};
    ll mx = 0;

    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        arr[i] = x;
        mp[x] ++;
        mx = max(mx , mp[x]);
        if(mp[x] == 1) {
            v.push_back(x);
        }
    }

    ll ans = 0;
    mp.clear();
    for(ll i = 0 ; i < n ; i++) {
        mp[arr[i]] ++;
        if(mp[arr[i]] == mx) {
            ans = arr[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
