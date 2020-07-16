#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , m;
    cin >> n >> m;
    ll arr[n][m];
    memset(arr , 0 , sizeof(arr));
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j ++) {
            cin >> arr[i][j];
        }
    }

    ll xr = 0;
    for(ll i = 0 ; i < n ; i ++) {
        xr ^= arr[i][0];
    }
    if(xr) {
        cout << "TAK" << endl;
        for(ll i = 0 ; i < n ; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else{
        ll val = 0;
        ll index = -1;
        for(ll i = 0 ; i < n ; i ++) {
            for(ll j = 0 ; j < m ; j ++) {
                if(arr[i][0] != arr[i][j]) {
                    arr[i][0] = arr[i][j];
                    index = i;
                    val = j + 1;
                    break;
                }
            }
            if(val) {
                break;
            }
        }
        if(val) {
            cout << "TAK" << endl;
            for(ll i = 0 ; i < n ; i++) {
                if(i != index) {
                    cout << 1 << " ";
                }
                else{
                    cout << val << " ";
                }
            }
            cout << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
    return 0;
}
