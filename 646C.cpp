#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        ll cnt = 0;
        ll degree[n + 1] = {0};

        for(ll i = 0 ; i < n - 1 ; i++) {
            ll u , v;
            cin >> u >> v;
            degree[u] ++;
            degree[v] ++;
            if(u == x || v == x) {
                cnt ++;
            }
        }

        ll ok = 0;
        for(ll i = 1 ; i <= n ; i++) {
            if(i == x && degree[i] <= 1) {
                ok = 1;
                break;
            }
        }

        if(ok) {
            cout << "Ayush" << endl;
        }
        else {
            ll diff = n - 2;
            if(diff % 2) {
                cout << "Ashish" << endl;
            }
            else {
                cout << "Ayush" << endl;
            }
        }
    }
    return 0;
}
