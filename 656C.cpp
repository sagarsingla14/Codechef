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
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        if(n == 1) {
            cout << 0 << endl;
        }
        else{
            ll index = n - 1;
            for(ll i = n - 1 ; i >= 1 ; i--) {
                if(arr[i] <= arr[i - 1]) {
                    index = i - 1;
                }
                else{
                    index = i - 1;
                    break;
                }
            }

            ll i = index;
            while(i >= 1 && arr[i] >= arr[i - 1]) {
                i --;
            }
            cout << i << endl;
        }
    }
    return 0;
}
