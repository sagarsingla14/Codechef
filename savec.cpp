#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans(ll num) {
    ll c = 0;
    while(num) {
        num /= 2;
        c ++;
    }
    return c;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll v[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> v[i];
        }
        ll l = v[0] , m = 0;
        for(ll i = 1; i < n ; i ++) {
            if(v[i] < l) {
                m = max(m , l - v [i]);
            }
            else {
                l = v[i];
            }
        }
        cout << ans(m) << endl;
    }
    return 0;
}
