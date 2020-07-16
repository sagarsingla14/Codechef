#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a , ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k , ans = 0;;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);


    }
    return 0;
}
