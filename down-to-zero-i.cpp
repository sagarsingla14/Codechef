#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll x , t;
ll dp[1000001] = {0};

void calc() {

    for(ll i = 0 ; i <= 1e6 ; i++) {
        dp[i] = 1e10;
    }
    dp[0] = 0;
    dp[1] = 1;

    for(ll i = 2 ; i <= 1e6 ; i++) {
        dp[i] = min(dp[i - 1] + 1 , dp[i]);

        for(ll j = 2 ; (j <= 1e3 && i * j <= 1e6) ; j++) {
            dp[i * j] = min(dp[i * j] , dp[max(i , j)] + 1);
        }
    }
}


int main() {
    calc();
    cin >> t;

    while(t--) {
        cin >> x;
        cout << dp[x] << endl;
    }
    return 0;
}
