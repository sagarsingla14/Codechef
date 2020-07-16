#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll mn = min(a, b);
        ll mx = max(a , b);
        if(mn == 0  && mx == 0) {
            cout << "YES" << endl;
            continue;
        }
        if(mx > 2 * mn) {
            cout << "NO" << endl;
        }
        else{
            if(mx == mn && mx % 2 && mn %2) {
                cout << "YES" << endl;
                continue;
            }
            if(abs(mx - mn) % 2) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
