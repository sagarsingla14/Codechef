#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , x;
    cin >> n >> x;
    ll arr[n] = {0};
    map <ll , ll> mp , xr;
    ll flag = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
        if(mp[arr[i]] >= 2) {
            flag = 1;
        }
    }
    if(flag) {
        cout << 0 << endl;
        return 0;
    }
    ll check = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll val = arr[i] & x;
        // cout << val << endl;
        xr[val] ++;
        if(val != arr[i]) {
            if(mp[val]) {
                flag = 1;
            }
        }
        if(xr[val] >= 2) {
            check = 1;
        }
    }
    if(flag) {
        cout << 1 << endl;
        return 0;
    }
    if(check) {
        cout << 2 << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
