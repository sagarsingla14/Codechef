#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll val = sum / n;
    ll ans = 0;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll diff = arr[i] - val;
        ans += abs(diff);
        arr[i + 1] += diff;
    }

    cout << ans << endl;
    return 0;
}
