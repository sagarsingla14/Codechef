#include <bits/stdc++.h>
#define ll long long int
#define mx 1000000000000000000
using namespace std;

string rev (string str) {
    string reverse = "";
    for(ll i = 0 ; i < str.length() ; i++) {
        reverse += str[str.length() - i - 1];
    }
    return reverse;
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    string str[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> str[i];
    }

    ll dp[n][2];
    // memset(dp , , sizeof(dp));
    for(ll i = 0 ; i < n ; i ++) {
        for(ll j = 0 ; j < 2 ; j ++) {
            dp[i][j] = mx;
        }
    }
    dp[0][0] = 0 , dp[0][1] = arr[0];
    ll flag = 0;

    for(ll i = 1 ; i < n ; i++) {
        // reverse(s.begin() , s.end()); // can be used
        string s1 = str[i - 1];
        string s1rev = rev(str[i - 1]);
        string s2 = str[i];
        string s2rev = rev(str[i]);
        // case - 1
        if(!(s1 > s2)) {
            dp[i][0] = min(dp[i][0] , dp[i - 1][0]);
        }
        if(!(s1rev > s2)) {
            dp[i][0] = min(dp[i][0] , dp[i - 1][1]);
        }
        if(!(s1 > s2rev)) {
            dp[i][1] = min(dp[i][1] , dp[i - 1][0] + arr[i]);
        }
        if(!(s1rev > s2rev)) {
            dp[i][1] = min(dp[i][1] , dp[i - 1][1] + arr[i]);
        }
        if(dp[i][0] == mx && dp[i][1] == mx) {
            flag = 1;
            break;
        }
    }

    if(flag) {
        cout << -1 << endl;
    }
    else{
        cout << min(dp[n - 1][0] , dp[n - 1][1]) << endl;
    }
    return 0;

}
