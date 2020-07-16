#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n , m , k;
    cin >> n >> m >> k;
    for(ll i = 0 ; i < k ; i++) {
        ll x, y;
        cin >> x >> y;
    }

    for(ll i = 0 ; i < k ; i++) {
        ll x, y;
        cin >> x >> y;
    }
    // cout << n + m + n * m - 3 << endl;
    string str = "";
    for(ll i = 0 ; i < m - 1 ; i++) {
        str += "L";
    }
    for(ll i = 0 ; i < n - 1 ; i++) {
        str += "U";
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m - 1 ; j++) {
            if(i % 2) {
                str += "L";
            }
            else{
                str += "R";
            }
        }
        str += "D";
    }
    cout << str.length() << endl;
    cout << str << endl;
    return 0;
}
