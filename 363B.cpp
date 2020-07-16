#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n] = {0};
    ll window = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        if(i < k) {
            window += arr[i];
        }
    }
    ll ans = 0;
    ll mn = window;
    for(ll i = 1 ; i < n - k ; i++) {
        window -= arr[i - 1];
        window += arr[i + k];
        if(window <= mn) {
            mn = window;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
