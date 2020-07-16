#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll phi[100001] = {0};
void preCalc() {
    phi[1] = 1;
    for(ll i = 0 ; i < 100001 ; i++) {
        phi[i] = i;
    }

    for(ll i = 2 ; i <= 100000 ; i ++) {
        if(phi[i] == i) {
            for(ll j = i ; j <= 100000 ; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    for(ll i = 1 ; i <= 100000 ; i++) {
        phi[i] += phi[i - 1];
    }
}

int main() {
    fast_io
    preCalc();

    ll t;
    cin >> t;

    ll c = 0;
    while(t--) {
        c ++;
        ll x;
        cin >> x;
        ll ans = x * (x + 1);
        ans >>= 1ll;
        cout << "Case " << c << ": " << ans - phi[x] << endl;
    }
    return 0;
}
