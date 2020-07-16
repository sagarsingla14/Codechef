#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    map <ll , ll> mp;
    ll o = 0 , z = 0;
    for(ll i = 0; i < n; i++) {
        if(str[i] == '0') {
            z ++;
        }
        else{
            o ++;
        }
        mp[o - z] = i;
    }

    z = 0 , o = 0;
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll x = o - z;
        if(mp[x]) {
            ans = max(ans, mp[x] - i + 1);
        }
        z += (str[i] == '0');
        o += (str[i] == '1');
    }
    cout << ans << endl;

    return 0;
}
