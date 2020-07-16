#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll h = 0 , a = 0 , r = 0 , d = 0;
ll n;
ll dp[4] = {0};

int main() {
    cin >> n;
    string str;
    cin >> str;
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        if(str[i] == 'h') {
            dp[0] += x;
        }
        else if(str[i] == 'a'){
            dp[1] = min(dp[0] , dp[1] + x);
        }
        else if(str[i] == 'r'){
            dp[2] = min(dp[1] , dp[2] + x);
        }
        else if(str[i] == 'd'){
            dp[3] = min(dp[2] , dp[3] + x);
        }
    }
    cout << dp[3] << endl;
    return 0;
}
