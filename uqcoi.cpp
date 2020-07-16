#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , q;
        cin >> n >> m >> q;
        vector <ll> v[n];
        unordered_set <ll> s;
        for(ll i = 0 ; i < n; i++) {
            for(ll j = 0 ; j < m ; j++){
                ll x;
                cin >> x;
                v[i].push_back(x);
                s.insert(x);
            }
        }

        ll sze = s.size() ;

        while(q--) {
            ll r , c , p;
            cin >> r >> c >> p;
            r-- ;
            c-- ;

            if(sze == 1) {
                if(p > v[0][0]) {
                    cout << n * m << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }
            else{
                ll arr[m] = {0};
                for(ll i = c ; i < m ; i++) {
                    if(i == c) {
                        if(v[0][i] < p) {
                            arr[i] = 1;
                        }
                    }
                    else {
                        if(v[0][i] < p) {
                            arr[i] = arr[i - 1] & 1;
                        }
                        else{
                            arr[i] = 0;
                        }
                    }
                }
                for(ll i = c ; i >= 0 ; i--) {
                    if(i == c) {
                        if(v[0][i] < p) {
                            arr[i] = 1;
                        }
                    }
                    else {
                        if(v[0][i] < p) {
                            arr[i] = arr[i + 1] & 1;
                        }
                        else{
                            arr[i] = 0;
                        }
                    }
                }
                ll ans = 0;
                for(ll i = 0 ; i < m ; i++) {
                    if(arr[i]) {
                        ans ++;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
