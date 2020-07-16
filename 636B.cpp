#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int

ll power(ll base , ll exp) {
    if(exp == 0) {
        return 1;
    }
    else {
        return base*power(base,exp-1);
    }
}
int main() {
    ll t;
    cin >> t;
    ll n;
    while(t--) {
        cin >> n;
        for(ll i = 2 ;i <= 30 ; i++) {
            ll pw = power(2LL , i);
            if(n % (pw - 1) == 0) {
                cout << n / (pw - 1) << endl;
                break;
            }
        }
    }
    return 0;
}
