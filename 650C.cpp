#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll odd = 0 , even = 0;;

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(i % 2 == 0 && arr[i] % 2 == 1) {
                even ++;
            }
            if(i % 2 == 1 && arr[i] % 2 == 0) {
                odd ++;
            }
        }

        if(odd != even) {
            cout << -1 << endl;
        }
        else{
            cout << min(odd , even) << endl;
        }
    }
    return 0;
}
