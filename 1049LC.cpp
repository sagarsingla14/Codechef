#include<bits/stdc++.h>
#define ll long long
using namespace std;

// 5
// 31 26 33 21 40


// [6,6,3,6,3,2,5,1]
// 6 6 3 6 3 2 5 1
//
int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    // priority_queue <ll> pq;
    for(ll i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
        // pq.push(arr[i]);
    }

    ll dp[n][n];
    // memeset(dp , 0 , sizeof(dp));

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            if(i == j) {
                dp[i][i] = arr[i];
            }
            else{
                dp[i][j] = INT_MAX;
            }
        }
    }
    for(ll i = 0 ; i < n - 1 ; i++) {
        dp[i][i + 1] = abs(arr[i] - arr[i + 1]);
    }
    for(ll l = 2 ; l < n ; l++) {
        for(ll i = 0 ; i < n - l ; i++) {
            ll end = i + l;
            for(ll j = i ; j < i + l ; j++) {
                // cout << i << " " << j << " " << end << endl;

                if(dp[i][end] >= abs(dp[i][j] - dp[j + 1][end])) {
                    dp[i][end] = abs(dp[i][j] - dp[j + 1][end]);
                }
            }
        }
    }
    // [3,3,6,4,8,8]
    // 3 3 6 4 8 8
    cout << dp[0][n - 1] << endl;
    ll mn = dp[0][n - 1];
    sort(arr , arr + n);
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            if(i == j) {
                dp[i][i] = arr[i];
            }
            else{
                dp[i][j] = INT_MAX;
            }
        }
    }
    for(ll i = 0 ; i < n - 1 ; i++) {
        dp[i][i + 1] = abs(arr[i] - arr[i + 1]);
    }
    for(ll l = 2 ; l < n ; l++) {
        for(ll i = 0 ; i < n - l ; i++) {
            ll end = i + l;
            for(ll j = i ; j < i + l ; j++) {
                // cout << i << " " << j << " " << end << endl;

                if(dp[i][end] >= abs(dp[i][j] - dp[j + 1][end])) {
                    dp[i][end] = abs(dp[i][j] - dp[j + 1][end]);
                }
            }
        }
    }
    cout << mn << " " << dp[0][n - 1] << endl;
    cout << min(mn , dp[0][n - 1]);
    return 0;
}
