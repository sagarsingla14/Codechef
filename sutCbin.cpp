#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ok = 1;
        ll arr[n + 1][n + 1];
        memset(arr , 0 , sizeof(arr));
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                cin >> arr[i][j];
            }
        }
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 1 ; j < n ; j++) {
                if(arr[i][j] == 1) {
                    if(arr[i + 1][j] == 1 || arr[i][j + 1] == 1) {
                        ok = 0;
                    }
                }

                if(!ok) {
                    break;
                }
            }
            if(!ok) {
                break;
            }
        }

        if(ok) {
            cout << "SAFE" << endl;
        }
        else{
            cout << "UNSAFE" << endl;
        }
    }
    return 0;
}
