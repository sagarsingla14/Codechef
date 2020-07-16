#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    while(n--) {
        if(str.length() == 1 && str[0] == '*') {
            cout << "YES" << endl;
            continue;
        }
        string s;
        cin >> s;
        ll ls = s.length();
        ll lstr = str.length();
        ll flag = 0;
        for(ll i = 0 ; i < lstr ; i++) {
            if(str[i] == '*') {
                break;
            }
            if(i >= ls) {
                flag = 1;
                break;
            }
            if(s[i] != str[i]) {
                if(str[i] != '*') {
                    flag = 1;
                    break;
                }
            }
        }
        ll j = ls - 1;
        for(ll i = lstr - 1 ; i >= 0; i--) {
            if(str[i] == '*') {
                break;
            }
            if(s[j] != str[i]) {
                if(str[i] != '*') {
                    flag = 1;
                    break;
                }
            }
            j--;
            if(j < 0) {
                break;
            }
        }

        if(flag) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
