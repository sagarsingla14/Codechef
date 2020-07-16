#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        set <ll> s;
        for(ll i = 1 ; i <= sqrtl(n); i++) {
            s.insert(i);
            s.insert(n / i);
        }
        cout << s.size() + 1 << endl;
        set <ll> :: iterator itr;
        cout << "0 ";
        for(itr = s.begin() ; itr != s.end() ; itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }
    return 0;
}
