#include "bits/stdc++.h"
#ifndef ll
#define ll long long int
#endif
using namespace std;
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        ll arr[n] = {0};
        ll sum[n+1] = {0};
        ll dp[n+1] = {0};

        for(ll i = 0; i < n ; i++) {
            cin>>arr[i];
        }
        dp[0] = 0;
        for(ll i = 1; i <= n ; i++) {
            sum[i] = sum[i-1] + arr[i-1];
            dp[i] = INT_MIN;
        }
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 0; j < i ; j++) {
                if((i - j) % 2 == 0) {
                    ll length = (i - j) / 2;
                    dp[i] = max(dp[i] , sum[j + length] - sum[j] + dp[j]);
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
