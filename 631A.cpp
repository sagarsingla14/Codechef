#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        ll arr[n] = {0};
        map <ll , ll> mp;
        for(ll i = 0 ; i <  n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
        }
        sort(arr , arr + n);
        ll place = 0;
        while(x--) {
            place ++;
            if(mp[place]) {
                x ++;
            }
            mp[place] = 1;
        }
        ll ans = place;
        while(mp[place] != 0) {
            place ++;
        }
        if(place == ans) {
            cout << ans << endl;
        }
        else{
            cout << place - 1 << endl;
        }
    }
    return 0;
}
