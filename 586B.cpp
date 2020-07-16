#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1][n + 1];

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            cin >> arr[i][j];
        }
    }
    
    ll ans = 0;
    for(ll i = 1 ; i <= n  ; i++) {
        if(i == 1) {
            ans = sqrt((arr[i][n - 1] * arr[i][n]) / (arr[n - 1][n]));
        }
        else if(i == 2) {
            ans = sqrt((arr[i][1] * arr[i][n]) / (arr[1][n]));
        }
        else {
            ans = sqrt((arr[i][1] * arr[i][2]) / arr[1][2]);
        }
        cout << ans << " ";
    }

    return 0;
}
