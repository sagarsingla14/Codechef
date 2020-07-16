#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll arr[n] = {0};
        for(ll i = 0; i < n ; i++) {
            cin >> arr[i];
        }

        ll index = 0;
        for(ll i = 31 ; i >= 0 ; i--) {
            ll mx = -1 , mxIndex = -1;
            for(ll j = index ; j < n ; j++) {
                ll bit = (arr[j] >> i) & 1;
                if(bit) {
                    if(arr[j] > mx) {
                        mxIndex = j;
                        mx = arr[j];
                    }
                }
            }

            if(mx == -1) {
                continue;
            }
            else {
                swap(arr[index] , arr[mxIndex]);
                for(ll j = 0 ; j < n ; j++) {
                    if(j != index) {
                        ll bit = (arr[j] >> i) & 1;
                        if(bit) {
                            arr[j] ^= mx;
                        }
                    }
                }
            }
            index ++;
        }

        ll ans = 0;
        for(ll i = 0 ; i < n ; i++) {
            ans ^= arr[i];
        }

        cout << ans << endl;
    }
    return 0;
}
