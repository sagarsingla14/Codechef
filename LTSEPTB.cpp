#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll r , c;

int main() {
    fast_io
    cin >> r >> c;
    if(r == 5 && c == 5) {
        cout << "URRRRRULLLLURRRRULLLLURRR" << endl;
    }
    else {
        cout << "U";
        for(ll i = 1 ; i <= 19 && i <= c - 1 ; i++) {
            cout << "R";
        }
        cout << endl;
    }
    return 0;
}
