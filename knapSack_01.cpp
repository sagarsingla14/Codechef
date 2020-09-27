#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n , w;
        cin >> n >> w;

        int wt[n] , val[n];

        for(int i = 0 ; i < n ; i++) {
            cin >> val[i];
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> wt[i];
        }

        int dp[2][w + 1];
        memset(dp , 0 , sizeof(dp));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j <= w ; j++) {
                if(wt[i] > j) {
                    dp[1][j] = dp[0][j];
                }
                else{
                    dp[1][j] = max(dp[0][j] , dp[0][j - wt[i]] + val[i]);
                }
            }
            for(int j = 0 ; j <= w ; j++) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }

        cout << dp[0][w] << endl;
    }
	return 0;
}
