#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        ll arr[n][m];
        ll cnt = 0;

        map <ll , ll> r , c;

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == 1) {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                if(arr[i][j] == 0) {
                    if(r[i] == 0 && c[j] == 0) {
                        cnt ++;
                        r[i] = 1;
                        c[j] = 1;
                    }
                }
            }
        }

        if(cnt % 2) {
            cout << "Ashish" << endl;
        }
        else{
            cout << "Vivek" << endl;
        }
    }
    return 0;
}
