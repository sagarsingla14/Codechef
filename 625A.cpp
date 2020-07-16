#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    map <ll , ll> mp;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i] - i] += arr[i];
    }
    ll ans = 0;
    for(auto itr = mp.begin() ; itr != mp.end() ; itr++) {
        ans = max(ans , itr -> second);
    }
    cout << ans << endl;
    return 0;
}
