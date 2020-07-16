#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , m;
    cin >> n >> m;
    vector <ll> v(m + 3);
    if(m % 2) {
        v[0] = (m / 2) + 1;
        v[1] = v[0] - 1;
        v[2] = v[0] + 1;
        for(ll i = 3 ; i < m ; i++) {
            if(i % 2) {
                v[i] = v[i - 2] - 1;
            }
            else{
                v[i] = v[i - 2] + 1;
            }
        }
    }
    else{
        v[0] = (m / 2);
        v[1] = (m / 2) + 1;
        for(ll i = 2 ; i < m ; i++) {
            if(i % 2 == 0) {
                v[i] = v[i - 2] - 1;
            }
            else{
                v[i] = v[i - 2] + 1;
            }
        }
    }

    ll freq = n / m;
    for(ll i = 0 ; i < freq ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cout << v[j] << endl;
        }
    }
    ll mod = n % m;
    for(ll i = 0 ; i < mod ; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
