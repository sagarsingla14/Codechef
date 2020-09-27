#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};

        ll one = 0 , zero = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i]) {
                one ++;
            }
            else{
                zero ++;
            }
        }
        if(one <= n / 2) {
            cout << n - one << endl;
            for(ll i = 0 ; i < zero ; i++) {
                cout << 0 << " ";
            }
            cout << endl;
        }
        else{
            if(zero % 2) {
                cout << one - 1 << endl;
                for(ll i = 0 ; i < one - 1 ; i++) {
                    cout << 1 << " ";
                }
                cout << endl;
            }
            else{
                cout << n - zero << endl;
                for(ll i = 0 ; i < one ; i++) {
                    cout << 1 << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
