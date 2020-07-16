#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , s;

int main() {
    cin >> n >> s;
    ll ans[n] = {0};
    if(s % n != 0) {
        if(s / n == 1) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            ll md = s % n;
            for(ll i = 0 ; i < n ; i++) {
                ans[i] = s / n;
            }
            for(ll i = 0 ; i < md ; i++) {
                ans[i] ++;
            }
            for(ll i = 0 ; i < n ; i ++) {
                cout << ans[i] << " ";
            }
            cout << endl;
            cout << 1 << endl;
        }
    }
    else{
        if(s / n == 1) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(ll i = 0 ; i < n ; i++) {
                cout << s / n << " ";
            }
            cout << endl;
            cout << 1 << endl;
        }
    }
    return 0;
}
