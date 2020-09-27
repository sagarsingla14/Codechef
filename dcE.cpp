#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1ll;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};

    ll sum = 0 , mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(arr[i] , mx);
    }

    ll ans = sum / (n - 1);

    if(sum % (n - 1)) {
        ans ++;
    }

    cout << max(ans , mx) << endl;

    return 0;
}
