#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
stack <ll> s;

int main() {
    fast_io
    cin >> n;
    ll impo = 0;
    ll mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        mx = max(mx , x);
        if(s.empty()) {
            s.push(x);
        }
        else if(s.top() < x) {
            impo = 1;
        }
        else if(s.top() == x) {
            s.pop();
        }
        else {
            s.push(x);
        }
    }

    if(impo) {
        cout << "NO" << endl;
    }
    else {
        if(s.size() > 1) {
            cout << "NO" << endl;
        }
        else {
            if(s.size() == 0) {
                cout << "YES" << endl;
            }
            else if(s.top() != mx) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
