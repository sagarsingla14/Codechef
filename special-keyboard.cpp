#include <bits/stdc++.h>
using namespace std;

int dp[76];
int n , t;

int solve(int x) {
    if(dp[x] != -1) {
        return dp[x];
    }

    int ans = 0;
    for(int i = x - 3 ; i >= 1 ; i--) {
        ans = max(ans , (x - i - 1) * solve(i));
    }
    dp[x] = ans;
    return dp[x];
}

void preCalc() {
    for(int i = 1 ; i <= 6 ; i++) {
        dp[i] = i;
    }
    for(int i = 7 ; i <= 75 ; i++) {
        solve(i);
    }
}

int main() {
    memset(dp , -1 , sizeof(dp));
    preCalc();

    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
