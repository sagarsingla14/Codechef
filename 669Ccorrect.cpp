#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    fast_io
    ll n; cin >> n;
    if(n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }

    vector <ll> v(n + 1 , 0);
    ll a, b;

    ll prev = 1;
    for(ll i = 2 ; i <= n ; i++) {
        cout << "?" << " " << prev << " " << i << endl;
        cin >> a;
        cout << "?" << " " << i << " " << prev << endl;
        cin >> b;

        if(a > b) {
            v[prev] = a;
            prev = i;
        }
        else{
            v[i] = b;
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(!v[i]) {
            v[i] = n;
        }
    }

    cout << "! ";
    for(ll i = 1 ; i <= n ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;

}
