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
        ll e = n / 4;
        if(n % 4) {
            e ++;
        }
        for(ll i = 0 ; i < n - e ; i++) {
            cout << "9";
        }
        for(ll i = 0 ; i < e ; i++) {
            cout << "8";
        }
        cout << endl;
    }
    return 0;
}
