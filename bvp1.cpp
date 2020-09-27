#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;


        set <ll> s;
        for(ll i = 1 ; i * i <= n ; i++) {
            if(n % i == 0) {
                s.insert(i);
                s.insert(n / i);
            }
        }

        ll ans = 0;
        for(auto i : s) {
            ans += i;
        }
        ans -= n;

        if(n == ans) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
