#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a , ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k , ans = 0;;
        cin >> n >> k;
        ll a[n] = {0};
        ll bb[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> bb[i];
        }
        sort(a , a + n);
        sort(bb , bb + n);

        ll b[n] = {0};
        ll z = 0;
        for(ll i = n - 1 ; i >= 0 ; i--) {
            b[z] = bb[i];
            z ++;
        }

        ll i = 0 , j = 0;
        ll cnt = 0;
        while(cnt < k && j < n && i < n) {
            if(a[i] < b[j]) {
                a[i] = b[j];
                cnt ++;
                i ++;
                j ++;
            }
            else{
                j ++;
            }
        }

        for(ll i = 0 ; i < n ; i ++) {
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
