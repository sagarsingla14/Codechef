#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        ll len = str.length();
        ll cnt = 0;
        string s = "abacaba";
        string add = "";
        for(ll i = 0 ; i <= 50 ; i++) {
            add += "x";
        }
        str += add;
        n = str.length();

        ll q = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '?') {
                q ++;
            }
        }

        for(ll i = 0 ; i <= n - 7 ; i++) {
            ll flag = 1;
            ll po = 0;
            for(ll j = i ; j < i + 7 ; j ++) {
                if(str[j] == s[po])  {

                }
                else{
                    flag = 0;
                }
                po ++;
            }
            if(flag) {
                cnt ++;
            }
        }

        if(cnt >= 2) {
            cout << "NO" << endl;
        }
        else if(cnt == 0 && q == 0) {
            cout << "NO" << endl;
        }
        else if(cnt == 1 && q == 0) {
            cout << "YES" << endl;
            for(ll i = 0 ; i < len ; i++) {
                if(str[i] == '?') {
                    cout << "x";
                }
                else{
                    cout << str[i];
                }
            }
            cout << endl;
        }
        else if(cnt == 1 && q > 0) {
            cout << "YES" << endl;
            for(ll i = 0 ; i < len ; i++) {
                if(str[i] == '?') {
                    cout << "x";
                }
                else{
                    cout << str[i];
                }
            }
            cout << endl;
        }
        else{
            cnt = 0;
            for(ll i = 0 ; i <= n - 7 ; i++) {
                ll flag = 1;
                ll po = 0;
                for(ll j = i ; j < i + 7 ; j ++) {
                    if(str[j] == s[po] || str[j] == '?')  {

                    }
                    else{
                        flag = 0;
                        break;
                    }
                    po ++;
                }
                if(flag) {
                    ll po = 0;
                    ll c = 0;
                    for(ll j = i + 7 ; j < i + 14 ; j++) {
                        if(str[j] == s[po]) {

                        }
                        else {
                            c = 1;
                            break;
                        }
                        po ++;
                    }
                    if(!c) {
                        flag = 0;
                    }
                }
                if(flag) {
                    cnt ++;
                    po = 0;
                    for(ll j = i ; j < i + 7 ; j ++) {
                        if(str[j] == '?')  {
                            str[j] = s[po];
                        }
                        po ++;
                    }
                }
                if(cnt) {
                    break;
                }
            }
            if(cnt) {
                cout << "YES" << endl;
                for(ll i = 0 ; i < len ; i++) {
                    if(str[i] == '?') {
                        cout << "x";
                    }
                    else{
                        cout << str[i];
                    }
                }
                cout << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
