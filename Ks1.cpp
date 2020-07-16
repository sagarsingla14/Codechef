#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        for(ll i = 1; i < n - 1 ; i++) {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                ans ++;
            }
        }
        cout << "Case #" << c << ": " << ans << endl;
        c ++;
    }
    return 0;
}
