#include <bits/stdc++.h>
using namespace std;

int t , n , ans = 0;
int dp[25][25];
int arr[25][25];

int main() {
    // cin >> t;
    // while(t--) {
    //     cin >> n;
    //     ans = 0;
    //
    //     memset(dp , 0 , sizeof(dp));
    //     memset(arr , 0 , sizeof(arr));
    //
    //     for(int i = 1 ; i <= n ; i++) {
    //         for(int j = 1 ; j <= n ; j++) {
    //             cin >> arr[i][j];
    //         }
    //     }
    //
    //     for(int i = 1 ; i <= n ; i++) {
    //         for(int j = 1 ; j <= n ; j++) {
    //             dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1] , max(dp[i - 1][j] , dp[i - 1][j + 1]));
    //         }
    //     }
    //
    //     for(int i = 1 ; i <= n ; i++) {
    //         ans = max(ans , dp[n][i]);
    //     }
    //
        int s = 0;
        while(s++ < 10) {
            cout << s << " ";
        }

        // cout << ans << endl;
    // }
    // return 0;
}
