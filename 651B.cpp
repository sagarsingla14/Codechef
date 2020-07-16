#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
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
        ll arr[2 * n] = {0};

        vector <pair <ll , ll>> even , odd;
        for(ll i = 0 ; i < 2 * n ; i++) {
            cin >> arr[i];
            if(arr[i] % 2 == 0) {
                even.push_back({arr[i] , i + 1});
            }
            else{
                odd.push_back({arr[i] , i + 1});
            }
        }

        ll e = even.size();
        ll o = odd.size();
        
        if(e % 2 == 0 && o % 2 == 0) {
            if(e > 0 && o > 0) {
                for(ll i = 0 ; i < e - 2 ; i += 2) {
                    cout << even[i].second << " " << even[i + 1].second << endl;
                }
                for(ll i = 0 ; i < o ; i += 2) {
                    cout << odd[i].second << " " << odd[i + 1].second << endl;
                }
            }
            else{
                if(e == 0) {
                    for(ll i = 0 ; i < o - 2 ; i += 2) {
                        cout << odd[i].second << " " << odd[i + 1].second << endl;
                    }
                }
                else {
                    for(ll i = 0 ; i < e - 2 ; i += 2) {
                        cout << even[i].second << " " << even[i + 1].second << endl;
                    }
                }
            }
        }
        else {
            for(ll i = 0 ; i < e - 1 ; i += 2) {
                cout << even[i].second << " " << even[i + 1].second << endl;
            }
            for(ll i = 0 ; i < o - 1 ; i += 2) {
                cout << odd[i].second << " " << odd[i + 1].second << endl;
            }
        }
    }
    return 0;
}
