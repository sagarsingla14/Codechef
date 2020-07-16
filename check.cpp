#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n , q ;
    cin >> n >> q ;
    ll arr[n + 1] = {0} ;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    ll last = 0 ;
    while(q--) {
        ll x , y;
        cin >> x >> y;
        ll l = ((x + last - 1) % n) + 1;
        ll r = ((y + last - 1) % n) + 1;

        if(l > r) {
            swap(l , r);
        }
        cout << l << " <- L  R -> " << r << endl;

        vector <ll> v;
        for(ll i = l ; i <= r ; i++) {
            v.push_back(arr[i]);
        }

        sort(v.begin() , v.end());
        cout << " Sorted " << endl;
        for(ll i = 0 ; i < v.size() ; i++){
            cout << v[i] << " ";
        }
        cout << endl;

        ll count = 1 , mx = 1;
        for(ll i = 0 ; i < v.size() - 1 ; i++){
            if(v[i] + 1 == v[i + 1]) {
                mx ++;
            }
            else{
                mx = 1;
            }
            count = max(mx , count);
            cout << mx << " <- mx  count -> " << count << endl;
        }

        // count = max(count , mx);
        last = count;
        cout << "last - > " << last << endl;
    }
    return 0;
}
