#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a ,b;
        cin >> a >> b;
        ll mod = a % b;
        if(mod == 0) {
            cout << 0 << endl;
            continue;
        }
        cout << b - mod <<endl;
    }
    return 0;
}
