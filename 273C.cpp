#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll arr[3] = {0};
    ll sum = 0;
    for(ll i = 0 ; i < 3 ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr , arr + 3);
    ll ans = sum / 3;

    if(2 * (sum - arr[2]) <= arr[2]) {
        ans = sum - arr[2];
    }
    cout << ans << endl;
    return 0;
}
