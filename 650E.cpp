#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        string str;
        cin >> str;
        map <char , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            mp[str[i]] ++;
        }

        ll ans = 0;
        for(ll i = n ; i >= 1 ; i--) {
            ll g = __gcd(k , i);
            ll div = i / g;
            ll cnt = 0;
            for(auto itr : mp) {
                cnt += (itr.second / div);
            }

            if(cnt >= g) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
