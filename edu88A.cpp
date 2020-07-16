#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , k;
        cin >> n >> m >> k;
        ll eq = n / k;
        if(eq >= m) {
            cout << m << endl;
        }
        else{
            ll rem = m - eq;
            ll sub =  rem / (k - 1);
            if(rem % (k - 1)) {
                sub ++;
            }
            cout << eq - sub << endl;
        }
    }
    return 0;
}
