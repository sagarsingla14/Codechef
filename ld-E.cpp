#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    string str;
    cin >> str;
    ll n = str.length();

    ll a = 0 , na = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == 'a') {
            a ++;
        }
        else{
            na ++;
        }
    }

    if(a == n) {
        cout << str << endl;
        return 0;
    }

    if(na & 1) {
        cout << ":(" << endl;
    }
    else{
        ll cnta = 0 , cntna = 0 , index = 0;
        na /= 2;

        for(ll i = 0 ; i < n ; i++) {
            if(cnta < a || cntna < na) {
                if(str[i] == 'a') {
                    cnta ++;
                }
                else {
                    cntna ++;
                }
            }
            else {
                index = i;
                break;
            }
        }

        string s1 = "" , s2 = "";

        for(ll i = 0 ; i < index ; i++) {
            if(str[i] != 'a') {
                s1 += str[i];
            }
        }

        for(ll i = index ; i < n ; i++) {
            if(str[i] != 'a') {
                s2 += str[i];
            }
        }

        if(s1 == s2) {
            for(ll i = 0 ; i < index ; i++) {
                cout << str[i];
            }
            cout << endl;
        }
        else {
            cout << ":(" << endl;
        }
    }
    return 0;
}
