#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n] = {0};
    vector <ll> v(n);
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        v[i] = arr[i];
    }

    if(n == 1) {
        cout << arr[0] << endl;
    }
    else {
        sort(arr , arr + n);
        if(k == 1) {
            cout << arr[0] << endl;
        }
        else if(k == 2) {
            ll ok = 0;

            if(v[0] == arr[n - 1] || v[n - 1] == arr[n - 1]) {
                cout << arr[n - 1] << endl;
            }
            else{
                ll ans = arr[1];
                ans = max(arr[1] , v[0]);
                ans = max(ans , v[n - 1]);
                cout << ans << endl;
            }
        }
        else {
            cout << arr[n - 1] << endl;
        }
    }

    return 0;
}
