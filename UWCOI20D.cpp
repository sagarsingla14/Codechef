#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n][n+1];
        for(ll i = 0 ; i < n; i++) {
            string str;
            cin >> str;
            for(ll j = 0 ; j < n ; j++) {
                if(i == 0 || j == 0) {
                    arr[i][j] = 0;
                }
                if(str[j] == '1') {
                    arr[i][j + 1] = 1;
                }
                else {
                    arr[i][j + 1] = 0;
                }
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < n ; j++) {
                
            }
        }
    }
}
