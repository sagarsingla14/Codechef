#include <bits/stdc++.h>
using namespace std;

int t;
unsigned long long int n;
unsigned long long int dp[501][10];

void preCalc() {
    memset(dp , 0 , sizeof(dp));
    for(unsigned long long int i = 1 ; i <= 500 ; i++) {
        for(unsigned long long int j = 0 ; j <= 9 ; j++) {
            if(i == 1) {
                dp[i][j] = j + 1;
            }
            else if(j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
}

int main() {
    preCalc();
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n][9] << endl;
    }
    return 0;
}
