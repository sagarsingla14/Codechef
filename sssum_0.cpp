#include <bits/stdc++.h>
using namespace std;

int dp[1000] = {0};
int arr[1000] = {0};
int n , m , t;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(dp , 0 , sizeof(dp));
        memset(arr , 0 , sizeof(arr));

        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        if(n >= m) {
            cout << 1 << endl;
        }
        else{
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < m ; j++) {
                    if(dp[j] == 1) {
                        if(dp[(j + arr[i]) % m] == 0) {
                            dp[(j + arr[i]) % m] = 2;
                        }
                    }
                }
                dp[arr[i] % m] = 1;
                for(int j = 0 ; j < m ; j ++) {
                    if(dp[j] == 2) {
                        dp[j] = 1;
                    }
                }
            }

            if(dp[0]) {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }

	return 0;
}
