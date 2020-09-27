#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007

int main() {
    ll n;
    cin >> n;
    string arr[n];
    ld ans = 0;

    map <string , ll> mp;
    mp["ACov(A)"] ++;
    mp["BCov(B)"] ++;
    mp["CCov(C)"] ++;
    mp["DCov(D)"] ++;
    mp["ECov(E)"] ++;
    mp["FCov(F)"] ++;


    vector <string> v;
    for(ll i = 0 ; i < 6 ; i++) {
        cin >> arr[i];
        if(mp[arr[i]]) {
            ans ++;
            mp[arr[i]] = 0;
        }
        else{
            v.push_back(arr[i]);
        }
    }

    vector <ll> r;
    for(auto i : mp) {
        if(i.second) {
            r.push_back(i.first);
        }
    }
    return 0;
}
