#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , a , b;
        cin >> n >> m >> a >> b;

        if(n * a == m * b) {
            cout << "YES" << endl;

            ll arr[n][m];
            ll row[n];
            ll col[m];

            memset(arr , 0 , sizeof(arr));
            memset(row , 0 , sizeof(row));
            memset(col , 0 , sizeof(col));

            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 0 ; j < m ; j ++) {
                    if(row[i] != a && col[j] != b) {
                        arr[i][j] = 1;
                        row[i] ++;
                        col[j] ++;
                    }
                }
            }

            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 0 ; j < m ; j ++) {
                    cout << arr[i][j];
                }
                cout << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
