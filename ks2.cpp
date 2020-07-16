#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n , d;
        cin >> n >> d;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        ll val[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            val[i] = (d / arr[i]) * arr[i];
        }

        for(ll i = n - 2 ; i >= 0 ; i--) {
            if(val[i] > val[i + 1]) {
                ll diff = abs(val[i + 1] - val[i]);
                ll mul = (diff / arr[i]);
                if(diff % arr[i] != 0) {
                    mul ++;
                }
                val[i] -= (arr[i] * mul);
            }
        }

        ans = val[0];

        cout << "Case #" << c << ": " << ans << endl;
        c ++;
    }
    return 0;
}
