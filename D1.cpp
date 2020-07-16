#include<bits/stdc++.h>
#define ll long long
using namespace std;

void output(string sub , ll start , string str) {
    ll l = sub.length();
    // cout << l << endl;
    string sfwd = "" ;
    for(ll i = l - 1 ; i >= 0  ; i--) {
        // cout << "i " << i << endl;
        ll flag = 0;
        for(ll j = 0 ; j <= i  ; j++) {
            if(sub[j] != sub[i - j]) {
                // cout << sub[j] << " " << sub[l - j - 1] << endl;
                flag = 1;
                break;
            }
        }
        // cout << flag << endl;
        if(!flag) {
            for(ll j = 0 ; j <= i ; j++) {
                sfwd += sub[j];
            }
            break;
        }
    }
    reverse(sub.begin() , sub.end());
    string sbwd = "";
    for(ll i = l - 1 ; i >= 0  ; i--) {
        ll flag = 0;
        for(ll j = 0 ; j <= i ; j++) {
            if(sub[j] != sub[i - j]) {
                flag = 1;
            }
        }
        if(!flag) {
            for(ll j = 0 ; j <= i ; j++) {
                sbwd += sub[j];
            }
            break;
        }
    }
    reverse(sbwd.begin() , sbwd.end());
    ll fl = sfwd.length();
    ll bl = sbwd.length();
    // cout << sfwd << " " << sbwd << endl;
    string mid = "";
    if(fl > bl) {
        mid = sfwd;
    }
    else{
        mid = sbwd;
    }

    for(ll i = 0 ; i < start ; i++) {
        cout << str[i];
    }
    // cout << endl;
    cout << mid ;
    // cout << endl;
    for(ll i = str.length() - start ; i < str.length() ; i++) {
        cout << str[i] ;
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll start = 0 , end = n;
        for(ll i = 0 ; i < n / 2 ; i++) {
            if(str[i] != str[n - i - 1]) {
                start = i;
                break;
            }
        }
        string sub = "";
        for(ll i = start ; i < n - start ; i++) {
            sub += str[i];
        }
        // cout << sub << endl;
        output(sub , start , str);
    }
    return 0;
}
