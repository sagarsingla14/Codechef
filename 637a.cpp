#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ;
        cin >> n;
        ll a , b , c , d;
        cin >> a >> b >> c >> d;
        ll rl = abs(c - d);
        ll rr = abs(c + d);
        ll wl = abs(a - b) * n;
        ll wr = abs(a + b) * n;
        ll ans = 1;
        if(wl > rr) {
            ans = 0;
        }
        else if(wr < rl){
            ans = 0;
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
