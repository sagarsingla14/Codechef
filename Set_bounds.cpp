#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    set <ll> s;
    while(n --) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    ll q; cin >> q;

    while(q--) {
        ll key;
        cin >> key;
        auto l = s.lower_bound(key);
        cout << "bound ";
        cout << *l << " ";
        l --;
        cout << *l << " ";
        cout << endl;
        auto itr = s.find(key);
        cout << "find " << *itr << endl;
        s.erase(itr);
        for(auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
