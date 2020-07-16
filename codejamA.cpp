#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        x ++;
        ll n , trace = 0;
        cin >> n;
        ll arr[n][n];
        memset(arr , 0 , sizeof(arr));
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < n ; j++) {
                cin >> arr[i][j];
                if(i == j) {
                    trace += arr[i][j];
                }
            }
        }
        ll r = 0 , c = 0;
        for(ll i = 0 ; i < n ; i++) {
            set <ll> row;
            set <ll> column;
            for(ll j = 0 ; j < n ; j++) {
                row.insert(arr[i][j]);
                column.insert(arr[j][i]);
            }

            if(row.size() != n) {
                r ++;
            }
            if(column.size() != n) {
                c ++;
            }
        }

        cout << "Case #" << x << ": " << trace << " " << r << " " << c << endl;
    }
    return 0;
}
