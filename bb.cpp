#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x ;
        cin >> n >> x;
        ll arr[n] = {0};
        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] = 1;
        }
        if(mp[x]) {
            cout << 1 << endl;
            continue;
        }
        sort(arr , arr + n);

        if(2 * arr[n - 1] >= x) {
            cout << 2 << endl;
            continue;
        }

        ll val = x - 2 * arr[n - 1];
        ll div = val / arr[n - 1];
        if(val % arr[n - 1]) {
            div ++;
        }
        cout << div + 2 << endl;
    }
    return 0;
}
