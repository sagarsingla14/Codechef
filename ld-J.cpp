#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , s;
    cin >> n >> s;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n);
    ll mid = arr[n / 2];

    ll ans = 0;

    if(mid == s) {
        cout << 0 << endl;
    }
    else if(mid <= s) {
        for(ll i = n / 2 ; i < n ; i++) {
            if(arr[i] <= s) {
                ans += (abs(arr[i] - s));
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    else{
        for(ll i = n / 2  ; i >= 0 ; i--) {
            if(arr[i] >= s) {
                ans += (abs(arr[i] - s));
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
