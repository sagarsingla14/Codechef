#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
            res *= x;
        }
        x *= x;
        y >>= 1;
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
        ll ok = 0;
        if(arr[n - 1] < arr[0] + arr[1]) {
            cout << -1 << endl;
        }
        else{
            cout << 0 + 1 << " " << 1 + 1 << " " << n << endl;
        }
    }
    return 0;
}
