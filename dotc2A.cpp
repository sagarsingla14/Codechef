#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main() {
    fast_io
    ll n , k;
    cin >> n >> k;
    map <ll , ll> mp;
    for(ll i = 0 ; i < k ; i++) {
        ll x;
        cin >> x;
        mp[x] ++;
    }

    ll ans = 0;
    for(ll i = 1 ; i <= 200 ; i++) {
        ll add = 0;
        for(auto itr : mp) {
            add += ((itr.second / i) * i);
        }
        
        add /= n;
        if(add >= i) {
            ans = i;
        }
        else{
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
