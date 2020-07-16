#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    vector <ll> dp[26];

    for(ll i = 0 ; i < 26 ; i ++) {
        for(ll j = 0 ; j <= n ; j++) {
            dp[i].push_back(0);
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        dp[str[i] - 'a'][i + 1] = 1;
    }

    for(ll i = 0 ; i < 26 ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        map <char , ll> cur;

        for(ll i = 0 ; i < s.length() ; i++) {
            cur[s[i]] ++;
        }

        ll index = 0;
        ll f = 1 , l = n;
        while(f <= l) {
            ll mid = (f + l) / 2;

            ll ok = 1;

            for(ll i = 0 ; i < 26 ; i++) {
                if(cur['a' + i] > dp[i][mid]) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                l = mid - 1;
                index = mid;
            }
            else{
                f = mid + 1;
            }
        }
        cout << index << endl;
    }
    return 0;
}
