#include <bits/stdc++.h>
using namespace std;

int n , sum = 0 , t;
long long int dp[1001][1001];
long long int mod = 1000000007;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n + 1] = {0};

        for(int i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }
        cin >> sum;
        memset(dp , 0 , sizeof(dp));

        dp[0][0] = 1;
        int index = 0;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 0 ; j <= sum ; j++) {
                if(j < arr[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                    dp[i][j] += (dp[i - 1][j - arr[i]] % mod);
                    dp[i][j] %= mod;
                }
            }
            index = i;
        }
        cout << dp[index][sum] << endl;
    }
	return 0;
}
