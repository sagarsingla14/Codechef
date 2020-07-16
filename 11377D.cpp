#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c;
        cin >> a >> b >> c;
        priority_queue <ll> aa;
        priority_queue <ll> bb;
        priority_queue <ll> cc;
        for(ll i = 0 ; i < a ; i++) {
            ll x;
            cin >> x;
            aa.emplace(x);
        }

        for(ll i = 0 ; i < b ; i++) {
            ll x;
            cin >> x;
            bb.emplace(x);
        }

        for(ll i = 0 ; i < c ; i++) {
            ll x;
            cin >> x;
            cc.emplace(x);
        }

        ll diff = 1e18;



    }

}
