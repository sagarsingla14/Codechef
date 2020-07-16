#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 10000000000000

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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        ll left = -1 , right = -1 , cent = -1;
        for(ll i = 1 ; i < n - 1 ; i++) {
            left = -1;
            right = -1;
            for(ll j = i + 1 ; j < n ; j++) {
                if(arr[j] < arr[i]) {
                    right = j + 1;
                    break;
                }
            }
            if(right == -1) {
                continue;
            }
            for(ll j = 0 ; j < i ; j++) {
                if(arr[i] > arr[j]) {
                    left = j + 1;
                }
            }
            if(left == -1) {
                continue;
            }
            if(left != -1 && right != -1) {
                cent = i + 1;
                break;
            }
        }
        if(cent == -1) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << left << " " << cent << " " << right << endl;
        }
    }
    return 0;
}
