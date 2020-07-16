#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b;
        cin >> a >> b;
        if(b == a) {
            cout << 0 << endl;
        }
        ll diff = abs(b - a);
        if(b > a) {
            if(diff % 2) {
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
        if(b < a) {
            if(diff % 2) {
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
    }
    return 0;
}
