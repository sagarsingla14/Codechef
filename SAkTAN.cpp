#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, q;
        cin >> n >> m >> q;
        map <ll, ll> row, column;

        while(q--) {
            ll r, c;
            cin >> r >> c;
            row[r] ++;
            column[c] ++;
        }

        ll re = 0, ro = 0 , ce = 0, co = 0;

        for(ll i = 1 ; i <= n ; i++) {
            if(row[i] % 2 == 0) {
                re ++;
            }
            else{
                ro ++;
            }
        }

        for(ll i = 1 ; i <= m ; i++) {
            if(column[i] % 2 == 0) {
                ce ++;
            }
            else{
                co ++;
            }
        }

        cout << (re * co) + (ce * ro) << endl;
    }
    return 0;
}
