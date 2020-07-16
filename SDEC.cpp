#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
    ll n , q;
    cin >> n >> q;
    map <ll , ll> a , b;
    vector <pair <ll , ll> > graph;
    map <ll , ll> bp;
    while(q--) {
        ll t , u , v;
        cin >> t >> u >> v;
        if((n == 1 || n == 2) && (t == 2)) {
            cout << "Yes" << endl;
            continue;
        }
        if(t == 1) {
            if(!a[u] && !b[u]) {
                if(a[v]) {
                    b[u] = 1;
                }
                else{
                    a[u] = 1;
                    b[v] = 1;
                }
            }
            else if(a[u] && !a[v]) {
                if(!b[v]) {
                    b[v] = 1;
                }
            }
            else if(b[u] && !b[v]) {
                if(!a[v]) {
                    a[v] = 1;
                }
            }
        }

        ll x = 0;
        if(a[u] && a[v]) {
            bp[u] = 1;
            bp[v] = 1;
        }
        if(b[u] && b[v]) {
            bp[u] = 1;
            bp[v] = 1;
        }

        if(t == 2) {
            ll ans = 0;
            if(bp[u] || bp[v]) {
                ans = 1;
            }
            if(ans) {
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
