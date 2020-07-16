#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    ll t;
    cin >> t;
    ll caseNumber = 0;
    while(t--) {
        caseNumber ++;
        ll x , y;
        string str;
        cin >> x >> y >> str;
        ll l = str.length();
        ll time = str.length();

        unordered_map <ll , vector <ll> > mp;

        vector <ll> v;
        ll mn = 1e10 , mx = -1000000;
        ll curtime = 0;
        for(ll i = 0 ; i < l ; i++) {
            if(str[i] == 'S') {
                curtime ++;
                y --;
                mp[y].push_back(curtime);
                v.push_back(y);
                mn = min(y , mn);
                mx = max(y , mx);
            }
            else {
                curtime ++;
                y ++;
                mp[y].push_back(curtime);
                v.push_back(y);
                mn = min(y , mn);
                mx = max(y , mx);
            }
        }
    }
    return 0;
}
