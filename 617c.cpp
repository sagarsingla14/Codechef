#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1) {
            cout << -1 << endl;
            continue;
        }
        string str;
        cin >> str;
        ll flag = 0;
        ll left = -1 , right = -1;
        for(ll i = 0 ; i < n - 1  ; i ++) {
            ll u = 0 , d = 0;
            if(str[i] == 'U') {
                if(str[i + 1] == 'D') {
                    left = i + 1;
                    flag = 1;
                }
            }
            if(str[i] == 'D') {
                if(str[i + 1] == 'U') {
                    right = i + 2;
                    flag = 1;
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) {
            cout << left << " " << right << endl;
            continue;
        }
        for(ll i = 0 ; i < n - 1  ; i ++) {
            ll l = 0 , r = 0;
            if(str[i] == 'L') {
                if(str[i + 1] == 'R') {
                    left = i + 1;
                    flag = 1;
                }
            }
            if(str[i] == 'R') {
                if(str[i + 1] == 'L') {
                    right = i + 2;
                    flag = 1;
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) {
            cout << left << " " << right << endl;
            continue;
        }

        if(n >= 4) {
            for(ll i = 0 ; i <= n - 4 ; i++) {

            }
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
