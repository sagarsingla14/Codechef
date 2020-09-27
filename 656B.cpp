#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[2 * n] = {0};
        for(ll i = 0 ; i < 2 * n ; i++) {
            cin >> arr[i];
        }
        map <ll , ll> mp;
        for(ll i = 0 ; i < 2 * n ; i++) {
            if(!mp[arr[i]]) {
                cout << arr[i] << " ";
                mp[arr[i]] ++;
            }
        }
        cout << endl;
    }
    return 0;
}
