#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll power(ll x , ll y){
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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll arr[n] = {0};

        map <ll , ll> mp;

        ll mx = 0;

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
        }

        map <ll , ll> ans;
        for(auto i : mp) {
            ans[i.second] ++;
            mx = max(mx , ans[i.second]);
        }

        ll mn = 10000000000000;
        for(auto i : ans) {
            if(i.second == mx) {
                mn = min(mn , i.first);
            }
        }

        cout << mn << endl;
    }
    return 0;
}
