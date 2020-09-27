#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int arr[101] = {0};
int n;

void print(vector <int> &ans) {
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

void printAllPair(int index , int sum , vector <int> &ans) {
    if(sum == 0) {
        print(ans);
        return;
    }

    if(dp[index - 1][sum]) {
        printAllPair(index - 1 , sum , ans);
    }

    if(arr[index] <= sum && dp[index - 1][sum - arr[index]]) {
        ans.push_back(arr[index]);
        printAllPair(index - 1 , sum - arr[index] , ans);
        ans.pop_back();
    }
    return;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        memset(dp , 0 , sizeof(dp));
        memset(arr , 0 , sizeof(arr));

        for(int i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        int sum;
        cin >> sum;

        dp[0][0] = 1;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 0 ; j <= sum ; j++) {
                if(j < arr[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - arr[i]];
                }
            }
        }

        if(dp[n][sum]) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

        vector <int> ans;
        printAllPair(n , sum , ans);
    }
	return 0;
}
