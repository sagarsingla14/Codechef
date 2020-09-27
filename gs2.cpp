#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


void Ans(ll x , ll y , ll n , ll m , map <pair <ll , ll> , ll> & mp) {
    if(y + 1 < m) {
        for(ll i = x ; i < n && i <= x + 1 ; i++) {
            mp[{i , y + 1}] = 1;
        }
        for(ll i = x ; i >= 0 && i >= x - 1 ; i--) {
            mp[{i , y + 1}] = 1;
        }
    }
    if(y - 1 >= 0) {
        for(ll i = x ; i < n && i <= x + 1 ; i++) {
            mp[{i , y - 1}] = 1;
        }
        for(ll i = x ; i >= 0 && i >= x - 1 ; i--) {
            mp[{i , y - 1}] = 1;
        }
    }

    for(ll i = x ; i >= 0 && i >= x - 2 ; i--) {
        mp[{i , y}] = 1;
    }

    for(ll i = x ; i < n && i <= x + 2 ; i++) {
        mp[{i , y}] = 1;
    }

    for(ll i = y ; i >= 0 && i >= y - 2 ; i--) {
        mp[{x , i}] = 1;
    }

    for(ll i = y ; i < m && i <= y + 2 ; i++) {
        mp[{x , i}] = 1;
    }

}

int main() {
    ll n , m , p;
    cin >> n >> m >> p;
    map <pair <ll , ll> , ll> mp;

    vector <pair <ll , ll>> v;
    for(ll i = 0 ; i < p ; i++) {
        ll x , y;
        cin >> x >> y;
        v.push_back({x , y});
    }

    for(auto i : v) {
        mp[{i.first , i.second}] = 1;
        Ans(i.first , i.second , n , m , mp);
    }

    cout << (n * m) - mp.size() << endl;
    return 0;
}
