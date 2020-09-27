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
        ll a , b , x , y , n;
        cin >> a >> b >> x >> y >> n;
        ll ans = 9e8;
        ll ans1 = 0 , ans2 = 0 , ans3 = 0;

        ll mn = abs(a - x);

        if(n > mn) {
            ll l = x;
            ll rem = n - mn;
            ll r = max(b - rem , y);
            ans1 = l * r;
        }
        else{
            ll l = a - n;
            ll r = b;
            ans1 = l * r;
        }

        mn = abs(b - y);
        if(n > mn) {
            ll l = y;
            ll rem = n - mn;
            ll r = max(a - rem , x);
            ans2 = l * r;
        }
        else{
            ll l = b - n;
            ll r = a;
            ans2 = l * r;
        }
        
        cout << min(ans1 , ans2) << endl;
    }
    return 0;
}
