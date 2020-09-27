#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k , t;
string str;

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> n >> k >> str;
        ll ok = 1;
        for(ll i = k ; i < n ; i++) {
            if(str[i] == str[i - k] && str[i] == '?') {
                continue;
            }
            else if(str[i] == '?' && str[i - k] != '?') {
                str[i] = str[i - k];
            }
            else if(str[i] != '?' && str[i - k] == '?') {
                str[i - k] = str[i];
            }
            else if(str[i] != str[i - k]) {
                ok = 0;
                break;
            }
        }

        if(!ok) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map <char , ll> mp;
        for(ll i = 0 ; i < k ; i++) {
            mp[str[i]] ++;
        }

        if(max(mp['0'] , mp['1']) > k / 2) {
            ok = 0;
        }

        if(!ok) {
            cout << "NO" << endl;
            continue;
        }

        for(ll i = k ; i < n ; i++) {
            mp[str[i]] ++;
            mp[str[i - k]] --;

            if(max(mp['0'] , mp['1']) > k / 2) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
