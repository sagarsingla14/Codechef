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

        if(n == 1) {
            cout << "FastestFinger" << endl;
        }
        else if(n == 2) {
            cout << "Ashishgup" << endl;
        }
        else if(n % 2 == 1) {
            cout << "Ashishgup" << endl;
        }
        else {
            ll lg = log2(n);
            ll pw = power(2ll , lg);
            if(pw == n) {
                cout << "FastestFinger" << endl;
            }
            else{
                if(n % 4 == 0) {
                    cout << "Ashishgup" << endl;
                }
                else{
                    map <ll , ll> mp;
                    ll x = n;
                    for(ll i = 2 ; i <= sqrt(x) ; i ++) {
                        while(x % i == 0) {
                            mp[i] ++;
                            x /= i;
                        }
                     }
                     if(x > 1) {
                         mp[x] ++;
                     }

                     if(mp.size() > 2) {
                         cout << "Ashishgup" << endl;
                     }
                     else {
                         vector <ll> v(2);
                         ll cnt = 0;
                         for(auto i : mp) {
                             v[cnt] = i.second;
                             cnt ++;
                         }

                         if(v[1] > 1) {
                             cout << "Ashishgup" << endl;
                         }
                         else {
                             cout << "FastestFinger" << endl;
                         }
                     }
                }
            }
        }
    }
    return 0;
}
