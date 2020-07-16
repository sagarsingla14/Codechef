#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <map>
#define base 1000000007
#define ll long long int
int main() {
    ll n , c , d;
    cin >> n >> c >> d;
    map <ll , ll> coins , dia;
    for(ll i = 0 ; i < n ; i++) {
        ll b , money;
        char cur;
        cin >> b >> money >> cur;
        if(cur == 'C') {
            coins[b] = money;
        }
        else{
            dia[b] = money;
        }
    }
    ll mxc = -1;
    map <ll , ll> :: iterator itr;
    for(itr = coins.begin() ; itr != coins.end() ; itr++) {
        ll val = itr -> second;
        if(val <= c) {
            mxc = max(mxc , itr -> first);
        }
    }
    ll mxd = -1;
    for(itr = dia.begin() ; itr != dia.end() ; itr++) {
        ll val = itr -> second;
        if(val <= d) {
            mxd = max(mxd , itr -> first);
        }
    }
    cout << mxc << " " << mxd << endl;
    if(mxd == -1 || mxc == -1) {
        cout << 0 << endl;
    }
    else{
        cout << mxd + mxc << endl;
    }
    return 0;
}
