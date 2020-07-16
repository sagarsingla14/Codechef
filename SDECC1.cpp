#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        set <char> s;
        for(ll i = 0; i < 3 ; i++) {
            s.insert(str[i]);
        }
        if(s.size() == 3) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
