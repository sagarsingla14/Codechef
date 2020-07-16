#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll solve(ll x) {
    return (x + 10);
}

int main() {
    fast_io
    ll n;
    cin >> n;

    solve(10);

    stack <ll> s;
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        if(s.empty()) {
            s.push(x & 1);
        }
        else if(s.top() == (x & 1)) {
            s.pop();
        }
        else {
            s.push(x & 1);
        }
    }

    if(s.size() > 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

    return 0;
}
