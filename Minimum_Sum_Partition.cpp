#include <bits/stdc++.h>
using namespace std;

int t , n , sum = 0;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        sum = 0;

        int arr[n] = {0};
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        int dp[sum + 1] = {0};
        dp[arr[0]] = 1;

        for(int i = 1 ; i < n ; i++) {
            for(int j = sum ; j >= 0 ; j --) {
                if(dp[j]) {
                    dp[j + arr[i]] = 1;
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0 ; i <= sum ; i++) {
            if(dp[i]) {
                ans = min(ans , abs(i - (sum - i)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
