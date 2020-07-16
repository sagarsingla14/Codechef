#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll one = 0 , zero = 0;
    ll l = str.length();
    for(ll i = 0 ; i < l ; i++) {
        if(str[i] == '1') {
            one++;
        }
        else{
            zero++;
        }
    }

    if(one) {
        cout << "1" ;
        for(ll i = 0 ; i < zero ; i++) {
            cout << "0";
        }
        cout << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
