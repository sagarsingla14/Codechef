#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
        ll ok = 1;
        for(ll i = 1 ; i < n ; i++) {
            if(abs(arr[i] - arr[i - 1]) == 1) {
                ok = 0;
            }
        }
        if(!ok) {
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}
