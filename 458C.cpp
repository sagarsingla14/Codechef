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
    ll c[n] = {0};
    ll ans = INFI;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> c[i];
    }

    for(ll i = 1 ; i < n - 1 ; i++) {
        ll cur = c[i];
        ll left = INFI;
        ll right = INFI;
        for(ll j = 0 ; j < i ; j ++) {
            if(arr[j] < arr[i]) {
                left = min(left , c[j]);
            }
        }
        for(ll j = i + 1 ; j < n ; j ++) {
            if(arr[j] > arr[i]) {
                right = min(right , c[j]);
            }
        }

        if(left != INFI && right != INFI) {
            cur += left + right;
            ans = min(ans , cur);
        }
    }
    if(ans == INFI) {
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}
