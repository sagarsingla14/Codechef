#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        ll arr[n + 1] = {0};
        ll cnt = 0;
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }
        if(arr[n] != 1) {
            cout << "NO" << endl;
        }
        else{
            ll ans = 1;
            for(ll i = 1 ; i < n ; i++) {
                if(arr[i] != i + 1) {
                    ans = 0;
                }
            }

            if(ans) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
