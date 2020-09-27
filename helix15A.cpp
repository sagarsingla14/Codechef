#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        ll ok = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll p;
            cin >> p;
            if(p > x) {
                ok = 1;
            }
        }
        if(ok) {
            cout <<"Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
