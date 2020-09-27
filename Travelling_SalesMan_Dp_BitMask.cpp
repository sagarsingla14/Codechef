#include <bits/stdc++.h>
using namespace std;

int t , n;
int graph[12][12];
int dp[5000][20];

int solve(int mask , int cur) {
    if(mask == (1 << n) - 1 && graph[cur][0]) {
        dp[mask][cur] = graph[cur][0];
        return graph[cur][0];
    }

    if(dp[mask][cur] != -1) {
        return dp[mask][cur];
    }

    int ans = INT_MAX;

    for(int i = 0 ; i < n ; i++) {
        if((mask & (1 << i)) == 0) {
            int newAns = graph[cur][i] + solve(mask | (1 << i) , i);
            ans = min(ans , newAns);
        }
    }
    return dp[mask][cur] = ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;

        memset(graph , 0 , sizeof(graph));
        memset(dp , -1 , sizeof(dp));

        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < n ; j ++) {
                cin >> graph[i][j];
            }
        }

        int mask = 1;
        cout << solve(mask , 0) << endl;
    }
	return 0;
}
