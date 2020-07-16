#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1][2];
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    ll dp[n + 1][3];
    memset(dp , 0 , sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[1][2] = 1;
    // if(arr[1][0] + arr[1][1] < arr[2][0] && arr[1][0] + arr[1][1] < arr[2][0] - arr[2][1]) {
    // }
    for(ll i = 2 ; i < n ; i++) {
        // left side
        ll ol = dp[i - 1][0];
        if(arr[i][0] - arr[i][1] > arr[i - 1][0]) {
            ol ++;
        }
        ll os = dp[i - 1][1];
        if(arr[i][0] - arr[i][1] > arr[i - 1][0]) {
            os ++;
        }
        ll orr = dp[i - 1][2];
        if(arr[i][0] - arr[i][1] > arr[i - 1][0] + arr[i - 1][1]) {
            orr ++;
        }
        ll mx = 0;
        mx = max(ol , os);
        mx = max(mx , orr);
        dp[i][0] = mx;
        mx = 0;

        // Stand
        ol = dp[i - 1][0];
        os = dp[i - 1][1];
        orr = dp[i - 1][2];
        mx = max(ol , os);
        mx = max(mx , orr);
        dp[i][1] = mx;
        mx = 0;

        // right
        ol = dp[i - 1][0];
        if(arr[i][0] + arr[i][1] < arr[i + 1][0] - arr[i + 1][1]) {
            ol ++;
        }
        os = dp[i - 1][1];
        if(arr[i][0] + arr[i][1] < arr[i + 1][0]) {
            os ++;
        }
        orr = dp[i - 1][2];
        if(arr[i][0] + arr[i][1] < arr[i + 1][0] ) {
            orr ++;
        }

        mx = max(ol , os);
        mx = max(mx , orr);
        dp[i][2] = mx;
    }

    // dp[n][1] = dp[n - 1][1];
    // ll ol = dp[n - 1][0];
    // if(arr[n][0] - arr[n][1] > arr[n - 1][0]) {
    //     ol ++;
    // }
    // ll orr = dp[n - 1][2];
    // if(arr[n][0] - arr[n][1] > arr[n - 1][0] + arr[n - 1][1]) {
    //     orr ++;
    // }
    //
    // dp[n][0] = max(ol , orr);
    // dp[n][0] = max(dp[n][0] , dp[n][1]);
    //
    // ol = dp[n - 1][0] + 1;
    // ll os = dp[n - 1][1] + 1;
    // orr = dp[n - 1][2];
    // if(arr[n - 1][0] + arr[n - 1][1] < arr[n][0]) {
    //     orr ++;
    // }
    // dp[n][2] = max(ol , orr);
    // dp[n][2] = max(dp[n][2] , os);
    dp[n][2] = max(dp[n - 1][0] + 1 , dp[n][2]);
    dp[n][2] = max(dp[n - 1][1] + 1 , dp[n][2]);
    if(arr[n - 1][0] + arr[n - 1][1] < arr[n][0]) {
        dp[n][2] = max(dp[n][2] , dp[n - 1][2] + 1);
    }
    else{
        dp[n][2] = max(dp[n][2] , dp[n - 1][2]);
    }


    // for(ll i = 0 ; i <= n ; i++) {
    //     cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    // }
    // dp[n][0] = dp[n - 1][0];
    // dp[n][1] = dp[n - 1][1];

    cout << dp[n][2] << endl;
    return 0;
}
