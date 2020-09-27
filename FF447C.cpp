#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << 1 << endl;
    }
    else{
        ll ans = 2;
        vector <ll> left(n , 1) , right(n , 1);
        for(ll i = 1 ; i < n ; i++) {
            if(arr[i - 1] < arr[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for(ll i = n - 2 ; i >= 0 ; i--) {
            if(arr[i] < arr[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        for(ll i = 1 ; i < n - 1 ; i++) {
            if(arr[i + 1] - arr[i - 1] > 1) {
                ans = max(ans , left[i - 1] + right[i + 1] + 1);
            }
        }

        for(ll i = 0 ; i < n - 1 ; i++) {
            ans = max(ans , left[i] + 1);
        }
        for(ll i = n - 1 ; i >= 1 ; i--) {
            ans = max(ans , right[i] + 1);
        }

        cout << ans << endl;
    }
    return 0;
}
