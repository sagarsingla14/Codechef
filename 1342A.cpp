#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll one = 0 , zero = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one ++;
            }
            else {
                zero ++;
            }
        }

        if(zero == n || one == n) {
            cout << str << endl;
        }
        else{
            string ans = "";
            for(ll i = 0 ; i < 2 * n ; i++) {
                if(i % 2) {
                    ans += '1';
                }
                else{
                    ans += '0';
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
