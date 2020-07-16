#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        sort(arr , arr + n);
        ll ans = 1e18;
        for(ll base = arr[0] ; base >= arr[0] - 2 ; base --) {
            ll curSum = 0;
            for(ll i = 0; i < n; i++) {
                ll diff = arr[i] - base;
                curSum += (diff / 5);
                diff %= 5;
                curSum += (diff / 2);
                diff %= 2;
                curSum += diff;
            }
            ans = min(ans, curSum);
        }
        cout << ans << endl;
    }
    return 0;
}
