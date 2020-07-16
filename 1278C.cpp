#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[2 * n] = {0};
        for(ll i = 0 ; i < 2 * n ; i++) {
            cin >> arr[i];
        }
        map <ll , ll> index;
        index[0] = -1;
        ll diff = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(arr[i] == 1) {
                diff ++;
            }
            else{
                diff --;
            }
            index[diff] = i;
        }
        // map <ll , ll> :: iterator itr;
        // for(itr = index.begin(); itr != index.end() ; itr++) {
        //     cout << itr -> first << " " << itr -> second << endl;
        // }
        ll ans = 2 * n;
        ll bwd = 0;
        for(ll i = 2 * n - 1 ; i >= n ; i--) {
            if(arr[i] == 1) {
                bwd ++;
            }
            else{
                bwd --;
            }
            // cout << bwd << endl;
            if(index.find(-bwd) != index.end()) {
                // ll d = i - index[-bwd];
                // cout << "d " << d << endl;
                ans = min(ans , i - index[-bwd] - 1);
            }
            // cout << " ans " << ans << endl;
        }
        ans = min(ans , 2 * n - index[0] - 1) ;
        cout << ans << endl;
    }
    return 0;
}
