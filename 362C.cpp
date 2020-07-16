#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans;
map <pair <ll , ll> , ll> mp;

void findAns(ll u , ll v) {
    while(u != v) {
        if(u > v) {
            ll next = (u >> 1);
            ans += mp[{u , next}];
            u >>= 1;
        }
        else{
            ll next = (v >> 1);
            ans += mp[{v , next}];
            v >>= 1;
        }
    }
}

void addValue(ll u , ll v , ll w) {
    while(u != v) {
        if(u > v) {
            ll next = (u >> 1);
            mp[{u , next}] += w;
            mp[{next , u}] += w;
             u >>= 1;
        }
        else{
            ll next = (v >> 1);
            mp[{v , next}] += w;
            mp[{next , v}] += w;
            v >>= 1;
        }
    }
}


int main() {
    ll q;
    cin >> q;
    while(q--) {
        ll t , u , v , w;
        cin >> t >> u >> v;
        if(t == 1) {
            cin >> w;
            addValue(u , v , w);
        }
        else {
            ans = 0;
            findAns(u , v);
            cout << ans << endl;
        }
    }
    return 0;
}
