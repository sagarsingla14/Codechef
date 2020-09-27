#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;

        string str;
        cin >> str;
        n = str.length();

        vector <ll> v;
        ll cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                cnt ++;
            }
            else{
                if(cnt) {
                    v.push_back(cnt);
                }
                cnt = 0;
            }
        }
        if(cnt) {
            v.push_back(cnt);
        }
        ll ans = 0;

        if(v.size() == 0) {
            cout << 0 << endl;
            continue;
        }

        sort(v.begin() , v.end());
        cnt = 0;
        for(ll i = v.size() - 1 ; i >= 0 ; i --) {
            if(cnt % 2 == 0) {
                ans += v[i];
            }
            cnt ++;
        }

        cout << ans << endl;
    }
    return 0;
}
