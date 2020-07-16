#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c , d , k;
        cin >> a>>b>> c>> d>> k;
        ll pen = ceil(a/c);
        if(a%c) {
            pen++;
        }

        ll pencil = ceil(b/d);
        if(b%d) { pencil++;
        }

        if(pen + pencil  <= k) {
            cout << pen << " " << pencil << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
