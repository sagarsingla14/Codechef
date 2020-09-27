#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll z;
    string str;
    cin >> str >> z;
    ll n = str.length();

    if((n * (n + 1)) / 2 < z) {
        cout << "No such line." << endl;
    }
    else {
        set <pair <string , ll> > s;
        for(ll i = 0; i < n ; i++) {
            string cur = "";
            cur += str[i];
            s.insert({cur , i});
        }

        pair <string , ll> ans;
        while(z--) {
            pair <string , ll> p = *s.begin();
            ans = *s.begin();
            s.erase(s.begin());
            if(p.second + 1 < n) {
                p.first += str[p.second + 1];
                p.second += 1;
                s.insert(p);
            }
        }

        cout << ans.first << endl;
    }
    return 0;
}
