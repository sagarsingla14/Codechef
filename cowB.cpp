#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll ans = 0;
        ll cnt = 0;
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll m;
        cin >> m;
        map <ll , ll> mp;
        for(ll i = 0 ; i < m ; i++) {
            ll x;
            cin >> x;
            mp[x] ++;
        }
        ll start = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(mp[arr[i]] == 0) {
                if(cnt) {
                    ans ++;
                }
                cnt = 0;
            }
            else{
                cnt ++;
            }
        }
        if(cnt) {
            ans ++;
        }

        cout << ans << endl;
    }
    return 0;
}
