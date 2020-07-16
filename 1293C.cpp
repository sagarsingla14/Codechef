#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <map>
#define base 1000000007
#define ll long long int
int main() {
    ll n , q;
    cin >> n >> q;
    map <pair <ll , ll> , ll> m;
    ll ans = 0;
    while(q--) {
        ll x , y;
        cin >> x >> y;
        if(m[{x , y}]) {
            m[{x , y}] --;
            if(m[{3  - x , y - 1}]) {
                m[{x , y}] --;
                m[{3  - x , y - 1}] --;
                ans --;
            }
            if(m[{3  - x , y}]) {
                m[{x , y}] --;
                m[{3  - x , y + 1}] --;
                ans --;
            }
            if(m[{3  - x , y + 1}]) {
                m[{x , y}] --;
                m[{3  - x , y + 1}] --;
                ans --;
            }
            m[{x , y}] = 0;
        }
        else{
            m[{x , y}] ++;
            if(m[{3  - x , y - 1}]) {
                m[{x , y}] ++;
                m[{3  - x , y - 1}] ++;
                ans ++;
            }
            if(m[{3  - x , y}]) {

                m[{3  - x , y + 1}] ++;
                m[{x , y}] ++;
                ans ++;
            }
            if(m[{3  - x , y + 1}]) {
                m[{x , y}] ++;
                m[{3  - x , y + 1}] ++;
                ans ++;
            }
        }
        if(ans > 0) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    map <pair <ll , ll> , ll> :: iterator i;
    for(i = m.begin() ; i != m.end() ; i++) {
        cout << (i -> first).first << endl;
    }
    for(auto &itr : m) {
        auto it = itr.first;
        cout << " " << it.first << " " << it.second << " " << itr.second << endl;
    }
    return 0;
}
