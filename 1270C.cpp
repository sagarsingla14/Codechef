#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ;
        cin >> n;
        ll arr[n] = {0};
        ll xr = 0 , sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            xr ^= arr[i];
            sum += arr[i];
        }
        if(sum == (2 * xr)) {
            cout << 0 << endl << endl;
            continue;
        }
        sum += xr;
        if(xr == 0) {
            cout << 1 << endl << sum << endl;
        }
        else{
            ll second = sum + xr;
            cout << 2 << endl << xr << " " << sum << endl;
        }
    }
}
