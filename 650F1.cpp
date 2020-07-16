#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> arr(n , 0);
        vector <ll> dp(n , 1);

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < i ; j ++) {
                if(arr[i] >= arr[j]) {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }

        if(dp[n - 1] == n) {
            cout << 0 << endl;
        }
        else{
            sort(dp.begin() , dp.end());
            cout << dp[n - 2] << endl;
        }
    }
    return 0;
}
