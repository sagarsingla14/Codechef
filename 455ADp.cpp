#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// Correct Solution in 455ADp.cpp
int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    ll mx = 0;
    for(ll i = 0 ; i < n ; i ++) {
        cin >> arr[i];
        mx = max(mx , arr[i]);
    }
    unordered_map <ll , ll> freq;
    for(ll i = 0 ; i < n ; i++) {
        freq[arr[i]] ++;
    }
    ll dp[mx + 1] = {0};
    dp[1] = freq[1];
    for(ll i = 2 ; i <= mx ; i++) {
        dp[i] = max(dp[i - 1] , dp[i - 2] + freq[i] * i);
    }
    cout << dp[mx] << endl;
    return 0;
}
