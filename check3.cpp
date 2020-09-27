// Operations : Right , Diagonal Right , Down

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;

	    int arr[n + 1][n + 1];
	    for(int i = 1 ; i <= n ; i++) {
	        for(int j = 1 ; j <= n ; j++) {
    	        cin >> arr[i][j];
    	    }
        }

	    int dp[n + 1][n + 1];
	    memset(dp , 0 , sizeof(dp));

	    for(int i = 2 ; i <= n ; i++) {
	        for(int j = 1 ; j <= n ; j++) {
	           if(i == 2 || j == 1) {
                   if(i == 1) {
                       dp[i][j] = dp[i][j - 1] + arr[i][j];
                   }
                   else{
                       dp[i][j] = dp[i - 1][j] + arr[i][j];
                   }
	           }
               else if(i == n) {
                   dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - 1]) + arr[i][j];
               }
	           else {
	               dp[i][j] = max(dp[i - 1][j - 1] , max(dp[i - 1][j] , dp[i][j - 1])) + arr[i][j];
	           }
	        }
	    }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        int ans = 0;

        for(int i = 1 ; i <= n ; i++) {
            for(int j = i ; j <= n ; j++) {
                ans = max(ans , arr[1][i] + dp[n][j]);
            }
        }
	    cout << ans << endl;
	}
	return 0;
}
