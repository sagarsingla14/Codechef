#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        // This diff should be initalised by 0
        ll diff = 0;
        ll mx = arr[0];
        for(ll i = 1 ; i < n ; i++) {
            if(arr[i] < mx) {
                diff = max(diff , mx - arr[i]);
            }
            else{
                mx = arr[i];
            }
        }
        // cout << diff << endl;
        ll ans = 0;
        while(diff) {
            ans ++;
            diff /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
