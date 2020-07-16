#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x , n , m;
        cin >> x >> n >> m;
        ll ans = 0;
        while(x >= 21 && n > 0) {
            // cout << "x "  << x << endl;
            x /= 2;
            x += 10;
            n --;
        }

        while(m > 0) {
            x -= 10;
            if(x <= 0) {
                ans = 1;
                break;
            }
            m --;
        }

        if(ans) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
