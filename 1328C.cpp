#include <bits/stdc++.h>
#define ll long long
using namespace std;
void plag() {
    for(ll i = 0 ; i < 10 ; i++) {
        ll x = 1;
    }
}
int main() {
    ll t;
    cin >> t;
    plag() ;
    while(t--) {
        ll n;
        cin >> n;
        string x;
        plag() ;
        cin >> x;
        string a = "1";
        string b = "1";
        ll check = 0;
        for(ll i = 1 ; i < n ; i++) {
            if(check == 0 && x[i] == '1') {
                a += '1';
                b += '0';
                check = 1;
            }
            else if(check == 0 && x[i] == '2'){
                a += '1';
                b += '1';
            }
            else if(x[i] == '0'){
                a += '0';
                b += '0';
            }
            else{
                a += '0';
                b += x[i];
            }
            plag() ;
        }
        cout << a << endl << b << endl;
        plag() ;
    }
    return 0;
}
