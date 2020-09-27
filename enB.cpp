#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t , x1 , y_1 , x2 , y2 , q , xd , yd , ok , ans;
string str;

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> str;
        ll mp[4] = {0};

        for(auto i : str) {
            if(i == 'L') {
                mp[0] ++;
            }
            if(i == 'R') {
                mp[1] ++;
            }
            if(i == 'U') {
                mp[2] ++;
            }
            if(i == 'D') {
                mp[3] ++;
            }
        }
        cin >> x1 >> y_1 >> q;

        ll left = x1 - mp[0];
        ll right = x1 + mp[1];
        ll down = y_1 - mp[3];
        ll up = y_1 + mp[2];

        while(q--) {
            cin >> x2 >> y2;
            ll ok = 0;

            if((x2 >= left && x2 <= right) && (y2 >= down && y2 <= up)) {
                ok = 1;
            }

            xd = x2 - x1;
            yd = y2 - y_1;

            if(ok) {
                cout << "YES " << abs(xd) + abs(yd) << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
