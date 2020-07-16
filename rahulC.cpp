#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans(ll num) {
    ll cur = 0;
    while(num != 0) {
        cur ++;
        num /= 2;
    }
    return cur;
}

int main() {
    ll t , n;
    cin >> t;
    while(t--) {
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll l = arr[0];
        ll sec = 0;
        for(ll i = 1 ; i < n ; i++) {
            if(arr[i] >= l) {
                l = arr[i];
            }
            else {
                sec = max(sec , l - arr[i]);
            }
        }

        cout << ans(sec) << endl;
    }
    return 0;
}
