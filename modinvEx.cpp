#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {

    ll m = 100001;
    ll inv[m + 1] = {0};
    inv[1] = 1;
    for(ll i = 2; i < m; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;

    ll cnt = 0;
    for(auto i : inv) {
        cout << cnt++ << " " << i << endl;
    }
    cout << endl;
}
