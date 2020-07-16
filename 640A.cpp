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
        vector <string> v;
        ll cnt = 0;
        for(ll i = n - 1 ; i >= 0 ; i--) {
            string s;
            if(str[i] != '0') {
                s += str[i];
                for(ll j = 0 ; j < cnt ; j++) {
                    s += '0';
                }
                v.push_back(s);
            }
            cnt ++;
        }

        cout << v.size() << endl;
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
