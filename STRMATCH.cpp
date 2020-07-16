#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , q;
string s;

int main() {
    fast_io
    cin >> n >> q;
    cin >> s;
    while(q--) {
        string str;
        cin >> str;
        ll l = str.length();

        str += '#';
        str += s;

        n = str.length();
        ll prefix[n] = {0};

        ll j = 0;
        for(ll i = 1 ; i < n ; i++) {
            while(j > 0 && str[i] != str[j]) {
                j = prefix[j - 1];
            }
            if(str[i] == str[j]) {
                j ++;
            }
            prefix[i] = j;
        }

        ll cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(prefix[i] == l) {
                cnt ++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
