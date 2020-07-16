#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        map <string , ll> m;
        for(ll i = 0 ; i < n ; i++) {
            string str;
            cin >> str;
            m[str] ++;
        }

        map <string , ll> :: iterator itr;
        ll ans = 0;
        for(itr = m.begin() ; itr != m.end(); m++) {
            if(itr -> second > 1) {
                ll freq = itr -> second;
                fre--;
                itr -> second = 1;
                string s;
                while(freq--) {
                    s = itr -> first;
                }
            }
        }

        ll ans = 0;
        

    }
}
