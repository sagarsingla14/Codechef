#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;
ll t , n;

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> str >> n;
        vector <ll> arr(n , 0);
        vector <ll> mp(26 , 0);
        vector <ll> visited(n , 0);

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        for(ll i = 0 ; i < str.length() ; i++) {
            mp[str[i] - 'a'] ++;
        }

        vector <char> ans(n , '-');
        for(ll i = 0 ; i < n ; i++) {
            vector <ll> v;
            for(ll j = 0 ; j < n ; j++) {
                if(arr[j] == 0 && !visited[j]) {
                    v.push_back(j);
                    visited[j] = 1;
                }
            }

            ll needMax = v.size();
            if(needMax == 0) {
                break;
            }
            ll ch;
            for(ll j = 25 ; j >= 0 ; j--) {
                if(mp[j] >= needMax) {
                    ch = j;
                    mp[j] = 0;
                    break;
                }
                else{
                    mp[j] = 0;
                }
            }

            for(auto j : v) {
                ans[j] = (ch + 'a');
            }

            for(ll j = 0 ; j < v.size() ; j++) {
                for(ll k = 0 ; k < n ; k ++) {
                    if(ans[k] == '-') {
                        ll sub = abs(v[j] - k);
                        arr[k] -= sub;
                    }
                }
            }
        }

        for(auto i : ans) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
