#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};

        for(ll i = 0; i < n ; i++) {
            cin >> arr[i];
        }

        ll ans = 0;
        unordered_map <ll , ll> mp;

        for(ll i = 0; i < n; i++) {
            ans = max(ans , mp[arr[i]]);
            for(ll j = 2 ; j <= sqrt(arr[i]) ; j++) {
                if(arr[i] % j == 0){
                    ll val = arr[i] / j;
                    if(val == j) {
                        mp[j] ++;
                    }
                    else{
                        mp[j] ++;
                        mp[val] ++;
                    }
                }
            }

            mp[1]++;
            mp[arr[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}
