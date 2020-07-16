#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n , m;
    cin >> n >> m;

    ll arr[n] = {0};
    for(ll i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr , arr + n);

    ll sum[n] = {0};
    sum[0] = arr[0];
    for(ll i = 1; i < n ; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    ll dp[n] = {0};
    for(ll i = 0; i < m; i++) {
        dp[i] = sum[i];
    }
    for(ll i = m; i < n ; i++) {
        dp[i] = dp[i - m] + sum[i];
    }

    for(ll i = 0; i < n ; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
