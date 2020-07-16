#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b , c ,d;
        cin >> a >> b >> c >> d;
        ll h = a - b;;
        ll v = c - d;
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

        if((x1 <= x - h && x - h <= x2)) {
            f1 = 1;
        }
        if((y1 <= y - v && y - v <= y2)) {
            f2 = 1;
        }

        if(x == x1 && x == x2) {
            if(a || b) {
                f1 = 0;
            }
        }

        if(y == y1 && y == y2) {
            if(c || d) {
                f2 = 0;
            }
        }

        if(f1 && f2) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
