#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n);

    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        ans += abs(arr[i] - arr[i + 1]);
        i ++;
    }

    cout << ans << endl;
    return 0;
}
