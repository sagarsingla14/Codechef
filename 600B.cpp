#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n , m;
    cin >> n >> m;
    ll arr[n] , brr[m] = {0};
    vector <ll> ar , br;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        ar.push_back(arr[i]);
    }
    for(ll i = 0 ; i < m ; i++) {
        cin >> brr[i];
        br.push_back(brr[i]);
    }
    sort(arr , arr + n);
    sort(brr , brr + m);

    ll a = 0, b = 0;
    ll flag = 0;
    map <ll , ll> mp;
    while(true ) {
        while(brr[b] >= arr[a]) {
            a ++;
            if(a >= n) {
                flag = 1;
                break;
            }
        }
        mp[brr[b]] = a;
        b ++;
        if(flag) {
            break;
        }
        if(b >= m) {
            break;
        }
    }
    while(b < m) {
        mp[brr[b]] = a;
        b ++;
    }


    for(ll i = 0 ; i < m ; i++) {
        cout << mp[br[i]] << " ";
    }
    cout << endl;
    return 0;
}
