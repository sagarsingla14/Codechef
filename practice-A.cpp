#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};

        vector <pair <ll , ll> > even;
        vector <pair <ll , ll> > odd;

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] % 2) {
                odd.push_back({arr[i] , i});
            }
            else{
                even.push_back({arr[i] , i});
            }
        }
        if(even.size()) {
            cout << 1 << endl << even[0].second + 1 << endl;
        }
        else{
            if(odd.size() >= 2) {
                cout << 2 << endl;
                cout << odd[0].second + 1 << " " << odd[1].second + 1 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
