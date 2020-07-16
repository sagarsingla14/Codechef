#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , k;

int main() {
    cin >> n;
    ll mx = 0;
    ll arr[n] = {0};
    map <ll , ll> mp;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mx = max(mx , arr[i]);
        mp[arr[i]] ++;
    }

    ll ans = 1;
    for(ll i = 2 ; i <= 100000 ; i++) {
        ll cnt = 0;
        for(ll j = 0 ; j < n ; j++) {
            if(arr[j] % i == 0) {
                cnt ++;
            }
        }
        ans = max(ans , cnt);
    }

    ll newVal = 0;
    for(auto i : mp) {
        if(i.first != 1) {
            if(ans < i.second) {
                ans =
                newVal = i.first;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
