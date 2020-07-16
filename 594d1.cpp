#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n , c = 0 , d = 0;
    cin >> n;
    string s;
    cin >> s;
    ll l = s.length();

    for(ll i = 0 ; i < l; i++) {
        if(s[i] == '(') {
            c++;
        }
        else{
            d++;
        }
    }

    if(c != d) {
        cout << 0 << endl << 1 << " " << 1 << endl;
    }
    else{
        string str;
        ll flag = 0;
        ll index = 0;
        for(ll i = 0; i < l ; i++) {
            if(s[i] == '(' && flag == 0) {
                flag = 1;
                index = i;
            }
            if(flag) {
                str += s[i];
            }
        }
        for(ll i = 0; i < index ; i++) {
            str += s[i];
        }
        // cout << str << endl;
        ll count = 0;
        stack <char> inside , outside;
        for(ll i = 0;  i < l ; i++) {
            if(str[i] == '(') {
                outside.push('(');
                ll flag = 0;
                for(ll j = i + 1 ; j < l ; j++) {
                    if(str[j] == '(') {
                        inside.push('(');
                        flag = 1;
                    }
                    else{
                        if(inside,empty) {

                        }
                        inside.pop();
                    }

                    if(inside.empty()) {
                        if(str[j+1] == ')') {
                            break;
                            ans = max(ans , count);
                        }
                        count++;
                    }
                }
            }
        }



    }
}
