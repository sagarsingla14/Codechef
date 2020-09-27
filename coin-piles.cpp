#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n , k , sum = 0;
	    cin >> n >> k;

        int arr[n + 1] , dp[n + 1] = {0};
	    for(int i = 1 ; i <= n ; i++) {
	        cin >> arr[i];
            sum += arr[i];
	    }

        sort(arr + 1 , arr + n + 1);

	    int ans = INT_MAX;
        for(int i = 1 ; i <= n ; i++) {
            dp[i] += dp[i - 1] + arr[i];
        }

	    for(int i = 1 ; i <= n ; i++) {
            int curSum = dp[i - 1];
            auto it = upper_bound(arr + 1 , arr + n + 1 , arr[i] + k) - arr;
            int remSum = sum - dp[it - 1];
            curSum += remSum - (n - it + 1) * (arr[i] + k);
            ans = min(ans , curSum);
	    }
	    cout << ans << endl;
	}
	return 0;
}
