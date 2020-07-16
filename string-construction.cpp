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

        map <char , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            mp[str[i]] ++;
        }
        cout << mp.size() << endl;
    }
    return 0;
}
