#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> v;
ll t , n;
string str;

ll power(ll  x , ll y) {
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

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> n >> str;
        ll cnt = 1;
        v.clear();

        for(ll i = 1 ; i < n ; i++) {
            if(str[i] == str[i - 1]) {
                cnt ++;
            }
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        if(cnt) {
            v.push_back(cnt);
        }

        if(v.size() == 1) {
            cout << ((n - 1) / 3) + 1 << endl;
        }
        else{
            ll s = v.size();
            if(s % 2) {
                v[0] += v[s - 1];
                v.pop_back();
            }
            ll ans = 0;
            for(auto i : v) {
                ans += (i / 3);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
