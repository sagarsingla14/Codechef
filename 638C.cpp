#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        string str;
        cin >> str;
        sort(str.begin() , str.end());

        map <char , ll> mp;
        set <char> s;
        for(ll i = 0 ; i < n ; i++) {
            mp[str[i]] ++;
            s.insert(str[i]);
        }
        if(k == 1) {
            cout << str << endl;
        }
        else{
            ll ok = 1;
            char ch;
            for(ll i = 0 ; i < k - 1 ; i++) {
                if(str[i] != str[i + 1]) {
                    ch = str[i + 1];
                    ok = 0;
                }
            }
            if(!ok) {
                cout << ch << endl;
                continue;
            }

            if(s.size() == 1) {
                ll val = str[0];
                ll mul = mp[str[0]] / k;
                if(mp[str[0]] % k != 0) {
                    mul ++;
                }
                for(ll i = 0 ; i < mul ; i++) {
                    cout << str[0];
                }
                cout << endl;
                continue;
            }

            ok = 1;

            if(str[k] == str[n - 1]) {
                string b = "";
                ll window = k;
                for(char i = 'a' ; i <= 'z' ; i++) {
                    ll rem = 0;
                    if(mp[i] > 0) {
                        ll val = mp[i];
                        ll mul = val / window;
                        rem = val % window;
                        for(ll j = 0 ; j < mul ; j++) {
                            b += i;
                        }
                        if(val % window == 0) {
                            window = k;
                        }
                        else{
                            window = val % k;
                        }
                    }
                    if(rem != 0) {
                        b += i;
                    }
                }
                cout << b << endl;
                continue;
            }

            string a = "";
            for(auto i : s) {
                mp[i] -= k;
                a += i;
                break;
            }
            for(auto i : mp) {
                ll mul = i.second;
                for(ll x = 0 ; x < mul ; x++) {
                    a += i.first;
                }
            }
            cout << a << endl;
        }
    }
    return 0;
}
