#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >>t;
    while(t--) {
        ll n;
        cin >> n;
        set <pair <ll , ll> , greater <pair <ll , ll >> > s;
        for(ll i = 0 ; i < n ; i++) {
            ll u , v;
            cin >> u >> v;
            s.emplace(make_pair(u , v));
        }

        set <pair <ll ,ll> ,  greater <pair <ll , ll >> > :: iterator itr;
        for(itr = s.begin() ; itr != s.end() ; itr++) {
            cout << itr -> first << " " << itr -> second << endl;
        }
    }
    return 0;
}
