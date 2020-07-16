#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == -1) {
            cout << -1 << endl;
        }
        else{
            ll arr[n] = {0};
            for(ll i = 0; i < n ; i++) {
                cin >> arr[i];
            }

            map <ll, ll> first;
            for(ll i = 0; i < n ; i++) {
                if(!first[arr[i]]) {
                    first[arr[i]] = i + 1;
                }
            }

            ll ans = INT_MAX;

            for(ll i = 0; i < n ; i++) {
                if(first[arr[i]] != i + 1) {
                    ll diff = abs(i + 1 - first[arr[i]]);
                    diff ++;
                    ans = min(ans , diff);
                    first[arr[i]] = i + 1;
                }
            }

            if (ans != INT_MAX) {
                cout << ans << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
