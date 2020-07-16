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
        ll ok = 0;
        ll index = -1;
        for(ll i = 0 ; i < n / 2 ; i++) {
            if(str[i] != str[n - i - 1]) {
                ok ++;
                index = i;
                break;
            }
        }

        if(ok) {
            string s = "";
            for(ll i = 0 ; i < n ; i++) {
                if(i != index) {
                    s += str[i];
                }
            }
            ok = 0;
            for(ll i = 0 ; i < s.length() / 2 ; i++) {
                if(s[i] != s[s.length() - i - 1]) {
                    ok = 1;
                    break;
                }
            }
            if(ok) {
                s = "";
                ok = 0;
                for(ll i = 0 ; i < n ; i++) {
                    if(i != (n - index - 1)) {
                        s += str[i];
                    }
                }
                for(ll i = 0 ; i < s.length() / 2 ; i++) {
                    if(s[i] != s[s.length() - i - 1]) {
                        ok = 1;
                        break;
                    }
                }
                if(ok) {
                    cout << -1 << endl;
                }
                else{
                    cout << (n - index - 1) << endl;
                }
            }
            else {
                cout << index << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
