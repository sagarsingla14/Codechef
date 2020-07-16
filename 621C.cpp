#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    string str;
    cin >> str;
    ll n = str.length();
    ll cnt[26] = {0};
    ll dp[26][26];
    memset(dp , 0 , sizeof(dp));

    for(ll i = 0 ; i < n ; i++) {
        ll index = str[i] - 'a';
        for(ll j = 0 ; j < 26 ; j ++) {
            dp[j][index] += cnt[j];
        }
        cnt[index] ++;
    }

    ll mx = 0;
    for(ll i = 0 ; i < 26 ; i++) {
        mx = max(cnt[i] , mx);
    }

    for(ll i = 0 ; i < 26 ; i++) {
        for(ll j = 0 ; j < 26 ; j++) {
            mx = max(mx , dp[i][j]);
        }
    }

    cout << mx << endl;
    return 0;
}
