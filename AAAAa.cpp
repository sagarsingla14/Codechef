#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b , c ,d;
        cin >> a >> b >> c >> d;
        ll h = abs(a - b);
        ll v = abs(c - d);
        ll f1 = 0 , f2 = 0;
        ll arr[6] = {0};
        for(ll i = 0 ; i < 6 ; i++) {
            cin >> arr[i];
        }
        ll x = arr[0];
        ll y = arr[1];
        ll x1 = arr[2];
        ll y1 = arr[3];
        ll x2 = arr[4];
        ll y2 = arr[5];
        if(a || b) {
            if(x1 > x || x2 < x) {
                f1 = 1;
            }
        }
        if(c || d) {
            if(y1 > y || y2 < y) {
                f2 = 1;
            }
        }

        if(f1 && f2) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
