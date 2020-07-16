#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll flag = 0;
        ll n;
        cin >> n;
        pair <ll , ll> arr[n];
        for(ll i = 0 ; i < n ; i++) {
            cin>>arr[i].first;
        }

        for(ll i = 0 ; i < n ; i++) {
            cin>>arr[i].second;
        }
        for(ll i = 0 ; i < n - 1 ; i++) {
            if(arr[i+1].first<arr[i].first) {
                flag = 1;
            }
        }
        if(!flag) {
            cout << "YES" << endl;
        }
        else {
            set <ll> s;
            ll fl=0;
            for(ll i = 0 ; i < n ; i++) {
                s.insert(arr[i].second);
            }
            if(s.size()==1) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
