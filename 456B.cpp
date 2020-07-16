#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll msb = 0;
ll n , k;

void findMsb() {
    ll temp = n;
    ll i = 0;
    while(temp) {
        if(temp & 1ll) {
            msb = i;
        }
        i ++;
        temp >>= 1ll;
    }
}


int main() {
    cin >> n >> k;

    findMsb();

    if(k == 1) {
        cout << n << endl;
        return 0;
    }
    else {
        ll ans = (1ll << msb);
        for(ll i = msb - 1 ; i >= 0 ; i--) {
            ans += (1ll << i);
        }
        cout << ans << endl;
    }

    return 0;
}
