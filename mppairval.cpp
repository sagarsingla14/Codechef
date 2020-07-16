#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    map <pair <ll , ll> , pair <ll , ll>> mp;
    mp[{1 , 3}] = {2 , 5};
    mp[{2 , 5}] = {2 , 5};
    mp[{4 , 6}] = {2 , 5};
    mp[{6 , 7}] = {2 , 5};
    mp[{10 , 8}] = {2 , 5};
    mp[{7 , 9}] = {2 , 5};

    map <pair <ll , ll> , pair <ll , ll> > :: iterator itr;
    for(itr = mp.begin() ; itr != mp.end() ; itr++) {
        cout << (itr->first).first << " " << (itr -> second).first << endl;;
    }

}
