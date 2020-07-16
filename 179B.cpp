#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
ll dp[501][501];
ll visited[501];
ll arr[501];
vector <ll> ans;



void floydWarshall() {
    for(ll k = n ; k >= 1 ; k--) {
        ll via = arr[k];
        visited[via] = 1;
        ll curAns = 0;
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                if(i != j) {
                    // Take care of this condition**
                    dp[i][j] = min(dp[i][j] , dp[i][via] + dp[via][j]);
                    if(visited[i] && visited[j]) {
                        curAns += dp[i][j];
                    }
                }
            }
        }
        ans.push_back(curAns);
    }
}

void printAnswer() {
    reverse(ans.begin() , ans.end());
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

void input() {
    memset(arr , 0 , sizeof(arr));
    memset(visited , 0 , sizeof(visited));
    memset(dp , 0 , sizeof(dp));

    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            cin >> dp[i][j];
        }
    }
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
}


int main() {

    input();
    floydWarshall();
    printAnswer();
    return 0;
}
