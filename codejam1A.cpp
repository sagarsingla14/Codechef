#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        ll n;
        x ++;
        cin >> n;
        string str[n];
        for(ll i = 0 ; i < n ; i++) {
            cin >> str[i];
        }
        ll l = 0;
        ll index = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i].length() > l) {
                l = str[i].length();
                index = i;
            }
        }

        string s = "";
        for(ll i = 1 ; i < str[index].length() ; i++) {
            s += str[index][i];
        }
        //
        // cout << " s - > " << s << endl;
        ll flag = 1;
        for(ll i = 0 ; i < n ; i++) {
            ll curLen = str[i].length();
            curLen --;
            ll diff = abs(s.length() - curLen);
            string s1 = "";
            for(ll j = 0 ; j < diff ; j++) {
                s1 += s[j];
            }
            for(ll j = 1 ; j < str[i].length() ; j++) {
                s1 += str[i][j];
            }

            // cout <<"S1 -> " << s1 << endl;
            if(s != s1) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            cout << "Case #" << x << ": " << s << endl;

            // cout << "Case #" << case << ": " << s << endl;
        }
        else{
            cout << "Case #" << x << ": *" << endl;
        }
    }
    return 0;
}
