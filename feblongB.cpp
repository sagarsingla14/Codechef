#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll m1 , y1 , m2 , y2;
        cin >> m1 >> y1 >> m2 >> y2;
        if(y1 % 4 || (y1 % 100 == 0 && y1 % 400 != 0)) {
            ll leap = 1;
            while (leap) {
                if(y1 == 1000000000) {
                    break;
                }
                y1 ++;
                if(y1 % 400 == 0 || (y1 % 4 == 0 && y1 % 100 != 0)) {
                    leap = 0;
                }
                m1 = 1;
            }
        }
        if(y2 % 4 || (y2 % 100 == 0 && y2 % 400 != 0)) {
            ll leap = 1;
            while (leap) {
                if(y2 == 1) {
                    break;
                }
                y2 --;
                if(y2 % 400 == 0 || (y2 % 4 == 0 && y2 % 100 != 0)) {
                    leap = 0;
                }
                m2 = 12;
            }
        }

        cout << m1 << " " << y1 << endl;
        cout << m2 << " " << y2 << endl;

        if(y1 > y2) {
            cout << 0 << endl;
        }
        else{
            ll ans = (abs(y2 - y1)) / 4;
            ans ++;

            if(m1 > 2) {
                ans --;
            }
            if(m2 < 2) {
                ans --;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
