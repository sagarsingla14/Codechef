#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    string str;
    cin >> n >> str;
    ll l = str.length();

    if(l % n) {
        string s = "1";
        for(ll i = 0 ; i < n - 1 ; i++) {
            s += "0";
        }
        for(ll i = 0 ; i < (l / n + 1) ; i++) {
            cout << s;
        }
        cout << endl;
    }
    else {
        string s = "";
        string ns = "";
        for(ll i = 0 ; i < n ; i++) {
            s += str[i];
        }
        for(ll i = 0 ; i < (l / n) ; i++) {
            ns += s;
        }

        cout << s << endl;
        if(s > str) {
            cout << s << endl;
        }
        else {
            if(s == str) {

            }
        }
    }
    return 0;
}
