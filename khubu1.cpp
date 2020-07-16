#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n = 20;
    unordered_map <ll, vector <ll> > mp;
    for(ll i = 1 ; i <= n ; i++) {
        if(n % i == 0) {
            for(ll j = i ; j <= n ; j += i) {
                if(!(j % i)) {
                    mp[i].push_back(j);
                }
            }
        }
    }
    unordered_map <ll , vector <ll> > :: iterator itr;
    for(itr = mp.begin() ; itr != mp.end() ; itr++) {
        ll key = itr -> first;
        for(ll j = 0 ; j < (itr -> second).size(); j++) {
            cout << itr -> second[j] << " ";
        }
        cout << endl;
    }
}
