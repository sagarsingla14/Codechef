#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        cin >> str;
        ll n = str.length();

        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            mp[str[i] - '0'] ++;
        }

        ll mx = 0;
        for(auto i : mp) {
            mx = max(i.second , mx);
        }
        mx = n - mx;

        ll mxCnt = 0;
        for(ll i = 0 ; i < 10 ; i++) {
            for(ll j = 0 ; j < 10 ; j++) {
                if(i != j) {
                    ll present = 0 , cnt = 0;
                    for(ll k = 0 ; k < n ; k++) {
                        if(str[k] - '0' == i) {
                            present = 1;
                        }
                        else if(str[k] - '0' == j) {
                            if(present) {
                                cnt ++;
                                mxCnt = max(mxCnt , cnt);
                            }
                            present = 0;
                        }
                    }
                }
            }
        }
        mxCnt = n - 2 * mxCnt;

        cout << min(mx , mxCnt) << endl;
    }
    return 0;
}
