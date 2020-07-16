#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
ll dp[501][501];

void floydWarshall() {
    for(ll k = 1 ; k <= n ; k++) {
        ll via = k;
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= n ; j++) {
                if(i != j && k != i && k != j) {
                    dp[i][j] = min(dp[i][j] , dp[i][via] + dp[via][j]);
                }
            }
        }
    }
}

void printAnswer() {
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void input() {
    memset(dp , 0 , sizeof(dp));

    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            dp[i][j] = 1e18;
        }
    }
    
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            cin >> dp[i][j];
        }
    }
}


int main() {

    input();
    floydWarshall();
    printAnswer();
    return 0;
}
