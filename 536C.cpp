#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , ans = 0;
ll arr[300001];

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n);
    for(ll i = 0 ; i < n / 2 ; i++) {
        ans += (arr[i] + arr[n - 1 - i]) * (arr[i] + arr[n - 1 - i]);
    }

    cout << ans << endl;
    return 0;
}
