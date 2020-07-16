#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    string str;
    cin >> str;
    ll n = str.length();

    map <char , ll> mp;

    for(auto i : str) {
        mp[i] ++;
    }

    ll mn = 1e10;

    ll one = 0;
    for(auto i : mp) {
        mn = min(mn , i.second);
        if(i.second == 1) {
            one ++;
        }
    }

    ll ok = 1;
    ll cnt = 0;
    for(auto i : mp) {
        ll val = i.second - mn;
        if(val > 1) {
            ok = 0;
            break;
        }
        if(val == 1) {
            cnt ++;
        }
    }
    if(cnt > 1) {
        ok = 0;
    }

    if(ok) {
        cout << "YES" << endl;
    }
    else{
        if(one != 1) {
            cout << "NO" << endl;
        }
        else{
            mn = 1e10;
            for(auto i : mp) {
                if(i.second != 1) {
                    mn = min(mn , i.second);
                }
            }

            ok = 1;

            for(auto i : mp) {
                if(i.second != 1) {
                    ll val = i.second - mn;
                    if(val) {
                        ok = 0;
                        break;
                    }
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

    return 0;
}
