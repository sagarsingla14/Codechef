#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , c;
        cin >> n >> m >> c;
        long double arr[c];
        for(ll i = 0 ; i < c ; i++) {
            cin >> arr[i];
        }

        sort(arr , arr + c , std::greater<long double>());
        // for(ll i = 0 ; i < c ; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        ll range = min(n , m);
        // cout << range << endl;
        long double ans = 0;
        ll count = 0;
        // cout << 2.0 * arr[0] << endl;
        for(ll i = 0 ; i < c ; i++) {
            if(ans >= range) {
                break;
            }
            else{
                count ++;
                ans += (2.0 * arr[i]);
            }
            // cout << ans << endl;
        }
        if(ans < range) {
            cout << -1 << endl;
        }
        else{
            cout << count << endl;
        }
    }
    return 0;
}
