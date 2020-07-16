#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int lds(int input1 , int input2[]) {

    int n = input1;
    int dp[n] = {0};

    for(int i = 0 ; i < n ; i++) {
        dp[i] = 1;
    }

    for(int i = 0 ; i < n - 1 ; i++) {
        for(ll j = i + 1 ; j < n ; j++) {
            if(input2[j] < input2[i]) {
                dp[j] = max(dp[j] , dp[i] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    ll arr[n] = {0};
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    cout << lds(n , arr) << endl;
    return 0;
}
