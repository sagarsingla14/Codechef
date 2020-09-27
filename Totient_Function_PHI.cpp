#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll phi[1000001] = {0};
void phiCalc() {
    phi[1] = 1;
    for(ll i = 0 ; i < 1000001 ; i++) {
        phi[i] = i;
    }

    for(ll i = 2 ; i <= 1000000 ; i ++) {
        if(phi[i] == i) {
            for(ll j = i ; j <= 1000000 ; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main() {
    fast_io
    preCalc();
    ll t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        cout << phi[x] << endl;
    }
    return 0;
}
