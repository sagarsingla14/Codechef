#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n , q;
    cin >> n >> q;
    ll dp[2][n + 2]= {(0,0)};
    while(q--) {
        ll x , y;
        cin >> x >> y;
        dp[x - 1][y - 1] = 1;
        if(x == 2) {
            if(dp[0][y - 2]) {
                dp[0][y - 2] ++;
            }
        }
        else{

        }

    }
}
