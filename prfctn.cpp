#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1) {
            cout << 0 << endl;
        }
        else{
            ll arr[n] = {0};
            ll mn = INT_MAX;
            for(ll i = 0 ; i < n ; i++) {
                cin >> arr[i];
                mn = min(mn , arr[i]);
            }
            vector <ll> v;
            for(ll i = 0; i < n - 1 ; i++) {
                if(arr[i] != arr[i + 1]) {
                    v.push_back(arr[i]);
                }
            }
            v.push_back(arr[n - 1]);
            ll ans = 0;
            for(ll i = 0 ; i < v.size() ; i++) {
                if(v[i] != mn) {
                    ans ++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
