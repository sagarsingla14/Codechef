#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

void solve() {
    int dp[r][c];
    memset(dp , 0 , sizeof(dp));

    for(ll i = 0 ; i < n ; i++) {

    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        ll s;
        cin >> str >> s;
        ll n = str.length();

        ll num = 0;
        for(ll i = 0 ; i < n ; i++) {
            num *= 10;
            num += (str[i] - '0');
        }

        ll sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            sum += (str[i] - '0');
        }

        if(sum <= s) {
            cout << 0 << endl;
        }
        else{
            vector <string> v;
            for(ll i = n - 1 ; i >= 0 ; i--) {
                for(char c = '0' ; c <= '9' ; c++) {
                    string cur = str;

                    cur[i] = c;
                    for(ll j = i + 1 ; j < n ; j++) {
                        cur[j] = '0';
                    }
                    v.push_back(cur);
                }
            }
            if(num < 1000000000000000000) {
                string cur = "1";
                for(ll i = 0 ; i < n ; i++) {
                    cur += '0';
                }
                v.push_back(cur);
            }

            ll ans = 9e18;
            for(ll i = 0 ; i < v.size() ; i++) {
                ll curNum = 0;
                ll dsum = 0;
                for(ll j = 0 ; j < v[i].size() ; j++) {
                    curNum *= 10;
                    curNum += (v[i][j] - '0');
                    dsum += (v[i][j] - '0');
                }

                if(curNum >= num && dsum <= s) {
                    ans = min(ans , curNum - num);
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}
