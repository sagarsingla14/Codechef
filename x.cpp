#include<bits/stdc++.h>
using namespace std;
#define ll int

int n;
int graph[12][12];
int dp[5000][12];


int solve(int mask , int pos){
	if(mask == (1 << n) - 1) {
		dp[mask][pos] = graph[pos][0];
        return dp[mask][pos];
	}
	if(dp[mask][pos] != -1) {
	   return dp[mask][pos];
	}

	int ans = INT_MAX;
	for(int i = 0 ; i < n ; i ++){
		if((mask & (1 << i)) == 0) {
			int newAns = graph[pos][i] + solve(mask | (1 << i) , i);
			ans = min(ans , newAns);
		}
	}

	return dp[mask][pos] = ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        memset(dp , -1 , sizeof(dp));
        memset(graph , -1 , sizeof(graph));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> graph[i][j];
            }
        }

        int mask = 1;
        cout << solve(mask , 0) << endl;
    }
    return 0;
}
