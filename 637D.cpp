#include <bits/stdc++.h>
#define ll long long int
using namespace std;

map <string , char> mp;
ll dp[10][8];
ll n , k;
ll ok;

void fillDp() {
    memset(dp , 0 , sizeof(dp));
    for(ll i = 0 ; i <= 9 ; i++) {
        for(ll j = 0 ; j <= 7 ; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    dp[0][1] = -1;
    dp[0][2] = 1;
    dp[0][3] = 7;
    dp[0][4] = 4;
    dp[0][5] = 5;
    dp[0][6] = 9;
    dp[0][7] = 7;

    dp[1][0] = 1;
    dp[1][1] = 7;
    dp[1][2] = 4;
    dp[1][3] = -1;
    dp[1][4] = 9;
    dp[1][5] = 8;
    dp[1][6] = -1;
    dp[1][7] = -1;

    dp[2][0] = 2;
    dp[2][1] = -1;
    dp[2][2] = 8;

    dp[3][0] = 3;
    dp[3][1] = 9;
    dp[3][2] = 8;

    dp[4][0] = 4;
    dp[4][1] = -1;
    dp[4][2] = 9;
    dp[4][2] = 8;

    dp[5][0] = 5;
    dp[5][1] = 9;
    dp[5][2] = 8;

    dp[6][0] = 6;
    dp[6][1] = 8;

    dp[7][0] = 7;
    dp[7][1] = -1;

    dp[7][2] = -1;
    dp[7][3] = 9;
    dp[7][4] = 8;

    dp[8][0] = 8;

    dp[9][0] = 9;
}

void setMap() {
    mp["1110111"] = '0';
    mp["0010010"] = '1';
    mp["1011101"] = '2';
    mp["1011011"] = '3';
    mp["0111010"] = '4';
    mp["1101011"] = '5';
    mp["1101111"] = '6';
    mp["1010010"] = '7';
    mp["1111111"] = '8';
    mp["1111011"] = '9';
}

char findNear(string str) {
    char ch;
    ll diff = 1e10;
    for(auto i : mp) {
        ll one = 0 , match = 0;
        string s = i.first;
        for(ll i = 0 ; i < s.size() ; i++) {
            if(s[i] == str[i] && s[i] != '0') {
                match ++;
            }
            if(s[i] == '1') {
                one ++;
            }
        }
        cout << "one match " << one << " " << match << endl;
        if(abs(match - one) <= diff) {
            ch = i.second;
            diff = abs(match - one);
        }
    }
    k -= diff;
    cout << "diff k " << diff <<  " " << k << endl;
    if(k < 0) {
        ok = 0;
    }
    return ch;
}

int main() {
    fillDp();
    setMap();
    cin >> n >> k;
    string num = "";
    string ans = "";
    string arr[n];
    ok = 1;
    for(ll i = 0 ; i < n ; i ++) {
        cin >> arr[i];
        if(mp.find(arr[i]) == mp.end()) {
            num += findNear(arr[i]);
        }
        else{
            num += mp[arr[i]];
        }
    }

    if(!ok) {
        cout << -1 << endl;
        return 0;
    }
    cout << "num " << num << " " << k << endl;

    for(ll j = 0 ; j < n ; j ++) {

        ll val = num[j] - '0';
        ll sticks = 0;
        ll dig = -1;
        for(ll i = 0 ; i <= 7 ; i++) {
            if(dp[val][i] != -1) {
                if(dp[val][i] >= dig) {
                    dig = dp[val][i];
                    sticks = i;
                }
            }
        }
        if(dig != -1) {
            char d = dig + '0';
            k -= sticks;
            ans += d;
        }
        if(k < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}
