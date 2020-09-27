#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

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
        sort(arr , arr + n);

        if(n == 1) {
            cout << "first" << endl;
        }
        else if(n == 2) {
            if(arr[0] != arr[1]) {
                cout << "first" << endl;
            }
            else {
                cout << "draw" << endl;
            }
        }
        else{
            ll p1 = 0 , p2 = 0;
            p1 += arr[n - 1];
            p2 += arr[n - 2];
            p2 += arr[n - 3];
            ll cnt = 0;
            for(ll i = n - 4 ; i >= 0 ; i--) {
                if(cnt % 2 == 0) {
                    p1 += arr[i];
                }
                else{
                    p2 += arr[i];
                }
                cnt ++;
            }

            if(p1 > p2) {
                cout << "first" << endl;
            }
            else{
                ll np1 = 0 , np2 = 0;
                np2 += arr[n - 1];
                np1 += arr[n - 2];
                np1 += arr[n - 3];
                cnt = 0;
                for(ll i = n - 4 ; i >= 0 ; i--) {
                    if(cnt % 2 == 0) {
                        np2 += arr[i];
                    }
                    else{
                        np1 += arr[i];
                    }
                    cnt ++;
                }

                if(np1 > np2) {
                    cout << "second" << endl;
                }
                else if(np1 == np2 && p1 == p2) {
                    cout << "draw" << endl;
                }
            }
        }
    }
    return 0;
}
