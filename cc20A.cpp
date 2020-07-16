#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while (t--) {
        ll n , k;
        cin >> n >> k;
        ll cnt = 0;

        ll impos = 0;
        ll arr[n] = {0};
        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
        }

        sort(arr , arr + n);

        for(ll i = 1 ; i < k ; i++) {
            if(mp[i] == 0) {
                impos = 1;
                break;
            }
        }

        if(impos) {
            cout << -1 << endl;
        }
        else{
            for(ll i = 0 ; i < n ; i++) {
                if(arr[i] != k) {
                    cnt ++;
                }
            }

            cout << cnt << endl;
        }
    }
    return 0;
}
