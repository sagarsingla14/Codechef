#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

map <ll , ll> mp;

void calcFac(ll x) {
    for(ll i = 2 ; i <= sqrt(x) ; i ++) {
        while(x % i == 0) {
            mp[i] = 1;
            x /= i;
        }
     }
     if(x > 1) {
         mp[x] = 1;
     }
}

int main() {
    ll n;
    cin >> n;

    vector <pair <ll, ll> > v;
    for(ll i = 0 ; i < n ; i++) {
        ll a , b;
        cin >> a >> b;
        v.push_back({a , b});
    }

    calcFac(v[0].first);
    calcFac(v[0].second);

    ll ans = -1;
    for(auto i : mp) {
        ll flag = 1;
        for(ll j = 0 ; j < n ; j++) {
            ll fac = i.first;
            if(v[j].first % fac != 0 && v[j].second % fac != 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            ans = i.first;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
