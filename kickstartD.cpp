#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n , k , p;
        cin >> n >> k >> p;
        ll arr[n][k];
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < k ; j++) {
                cin >> arr[i][k];
            }
        }
        if(n == 1) {
            ll ans = 0;
            for(ll i = 0 ; i < p ; i++) {
                ans += arr[0][i];
            }
            cout << "Case #" << c << ": " << ans << endl;
        }
        if(n == 2) {
            
        }

        cout << "Case #" << c << ": " << ans << endl;
        c++;
    }
    return 0;
 }
