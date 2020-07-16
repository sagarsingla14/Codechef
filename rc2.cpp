#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        if(str.length() == 1 || str.length() == 2) {
            cout << "YES" << endl;
        }
        else{
            set <char> s;
            for(ll i = 0 ; i < n ; i++) {
                s.insert(str[i]);
            }

            if(s.size() > 2) {
                cout << "NO" << endl;
            }
            else{
                if(n % 2 && s.size() > 1) {
                    cout << "NO" << endl;
                }
                else {
                    ll ok = 1;
                    for(ll i = 0 ; i < n ; i++) {
                        if(str[i] != str[(i + 2) % n]) {
                            ok = 0;
                        }
                    }

                    if(ok) {
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }

            }
        }
    }
    return 0;
}
