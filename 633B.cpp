#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    cout << pow(2 , 64) << endl;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        vector <pair <ll , ll> > v;
        ll arr[n] = {0};
        for(ll i = 0; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
        for(ll i = 0 ; i < n / 2 ; i++) {
            v.push_back(make_pair(arr[i] , arr[n - 1 - i]));
        }

        if(n % 2) {
            cout << arr[n / 2] << " ";

            for(ll i = v.size() - 1 ; i >= 0 ; i--) {
                cout << v[i].first << " " << v[i].second << " ";
            }
            cout << endl;
        }
        else{
            for(ll i = v.size() - 1 ; i >= 0 ; i--) {
                cout << v[i].first << " " << v[i].second << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
