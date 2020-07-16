#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t , n;

ll check(string str) {
    ll ok = 1;
    for(ll i = 1 ; i < str.length() ; i++) {
        ll val = abs(str[i] - str[i - 1]);
        if(val == 1) {
            ok = 0;
            break;
        }
    }
    return ok;
}

int main() {
    fast_io
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        n = str.length();
        string o = "" , e = "";
        map <char , ll> mp;
        for(ll i = 0 ; i < n ; i ++) {
            if((str[i] - 'a') % 2 && !mp[str[i]]) {
                o += str[i];
                mp[str[i]] ++;
            }
            else if((str[i] - 'a') % 2 == 0 && !mp[str[i]]) {
                e += str[i];
                mp[str[i]] ++;
            }
            else {
                mp[str[i]] ++;
            }
        }

        sort(o.begin() , o.end());
        sort(e.begin() , e.end());

        if(check(o + e)) {
            str = "";
            str += o;
            str += e;
            for(ll i = 0 ; i < str.length() ; i++) {
                for(ll j = 0 ; j < mp[str[i]] ; j++) {
                    cout << str[i];
                }
            }
            cout << endl;
        }
        else if(check(e + o)) {
            str = "";
            str += e;
            str += o;
            for(ll i = 0 ; i < str.length() ; i++) {
                for(ll j = 0 ; j < mp[str[i]] ; j++) {
                    cout << str[i];
                }
            }
            cout << endl;
        }
        else {
            cout << "No answer" << endl;
        }
    }
    return 0;
}
