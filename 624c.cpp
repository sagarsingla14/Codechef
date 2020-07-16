#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        string str;
        cin >> str;
        ll p[m] = {0};
        for(ll i = 0 ; i < m ; i++) {
            cin >> p[i];
        }
        ll l = str.length();
        ll arr[26][l + 1];
        for(ll i = 0 ; i < 26 ; i++) {
            for(ll j = 0 ; j <= l; j++) {
                arr[i][j] = 0;
            }
        }

        for(ll i = 0 ; i < l ; i++){
            arr[str[i] - 'a'][i + 1] = 1;
        }

        for(ll i = 0; i < 26 ; i++) {
            for(ll j = 1 ; j <= l ; j ++) {
                arr[i][j] += arr[i][j - 1];
            }
        }

        ll ans[26] = {0};
        for(ll i = 0 ; i < m ; i++) {
            ll f = 0 , l = p[i];
            for(ll j = 0 ; j < 26 ; j ++) {
                ans[j] += abs(arr[j][f] - arr[j][l]);
            }
        }
        for(ll i = 0 ; i < 26 ; i++) {
            ans[i] += arr[i][l];
        }

        for(ll i = 0 ; i < 26 ; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
