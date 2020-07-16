#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    set <ll> s;
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        if(x) {
            s.insert(x);
        }
    }

    cout << s.size() << endl;
    return 0;
}
