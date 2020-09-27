#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string s,t;
        cin >> s >> t;
        map <char , ll> ss;
        for(ll i = 0 ; i < s.size() ; i++) {
            ss[s[i]] = 1;
        }
        ll ans = 0;
        for(ll i = 0 ; i < t.size() ; i++) {
            if(ss[t[i]]) {
                ans = 1;
                break;
            }
        }

        if(ans == 1) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
