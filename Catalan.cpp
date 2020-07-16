#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll ncr[10001][10001];
void calcNCR() {
    ncr[0][0] = 1;
    ncr[1][0] = 1;
    ncr[1][1] = 1;

    for(ll i = 0 ; i <= 10000 ; i++) {
        ncr[i][0] = 1;
    }
    for(ll i = 2 ; i <= 10000 ; i++) {
        for(ll j = 1 ; j <= i ; j++) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}

ll ans(ll x) {
    ll res = ncr[2 * x][x];
    res /= (x + 1);
    return res;
}

int main() {
    memset(ncr , 0 , sizeof(ncr));
    calcNCR();

    ll q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        cout << ans(x) << endl;
    }
    return 0;
}
