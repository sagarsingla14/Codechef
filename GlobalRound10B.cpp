#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;

        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        vector <ll> v;
        ll mx = -1000000000000;
        ll mn = 1000000000000;
        for(ll i = 0 ; i < n ; i++) {
            mx = max(mx , arr[i]);
            mn = min(mn , arr[i]);
        }

        for(ll i = 0 ; i < n ; i++) {
            v.push_back(mx - arr[i]);
        }
        if(k == 1) {
            for(auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            mx = -10000000000000;
            vector <ll> ans;
            for(auto i : v) {
                mx = max(mx , i);
            }
            if(k % 2) {
                for(auto i : v) {
                    cout << i << " ";
                }
                cout << endl;
            }
            else{
                for(auto i : v) {
                    cout << mx - i << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
