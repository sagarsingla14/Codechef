#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n <= 3) {
            cout << -1 << endl;
        }
        else{
            vector <ll> v;
            for(ll i = 1 ; i <= n ; i += 2) {
                v.push_back(i);
            }

            if(n & 1) {
                for(ll i = n - 1 ; i >= 2 ; i -= 2) {
                    v.push_back(i);
                }

                swap(v[n / 2 - 2] , v[n / 2 - 1]);
                swap(v[n / 2 - 1] , v[n / 2]);
            }
            else{
                for(ll i = n ; i >= 2 ; i -= 2) {
                    v.push_back(i);
                }
                swap(v[n / 2 - 2] , v[n / 2 - 1]);
            }

            for(auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
