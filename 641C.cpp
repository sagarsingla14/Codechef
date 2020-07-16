#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , ans = 0;
ll arr[200001] = {0};
ll dp[200001] = {0};

int main() {
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    dp[n] = arr[n];
    for(ll i = n - 1 ; i >= 1 ; i --) {
        dp[i] = __gcd(dp[i + 1] , arr[i]);
    }

    for(ll i = 1 ; i <= n - 1 ; i ++) {
        ll curGcd = (arr[i] * dp[i + 1]) / dp[i];
        if(i == 1) {
            ans = curGcd;
        }
        else{
            ans = __gcd(ans , curGcd);
        }
    }
    cout << ans << endl;
    return 0;
}
