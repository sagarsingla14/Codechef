#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , d;
        cin >> n >> d;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        for(ll i = 1 ; i< n ; i++) {
            while (arr[i] && d - i >= 0) {
                arr[0] ++;
                arr[i] --;
                d -= i;
            }
        }
        cout << arr[0] << endl;
    }
    return 0;
}
