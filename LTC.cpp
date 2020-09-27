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
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        vector <ll> v;

        ll cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(arr[i] == 0) {
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


        if(v.size() == 0) {
            cout << "No" << endl;
            continue;
        }

        if(v.size() == 1) {
            if(v[0] % 2 == 0) {
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
            continue;
        }

        sort(v.rbegin() , v.rend());
        // for(auto i : v) {
        //     cout << i << " ";
        // }
        // cout << endl << endl;

        if(v[0] % 2 == 0) {
            cout << "No" << endl;
        }
        else {
            ll val = (v[0] % 2) + (v[0] / 2);
            if(val <= v[1]) {
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
