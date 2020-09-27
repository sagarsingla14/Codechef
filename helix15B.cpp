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
        ll n;
        cin >> n;
        ll ok = 0;
        for(ll i = 1 ; i <= sqrt(1000000001) ; i++) {
            if((i * (i + 1)) / 2 == n) {
                ok = 1;
                break;
            }
        }
        if(ok) {
            cout << "Possible" << endl;
        }
        else{
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
