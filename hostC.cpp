#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check(ll x) {
    unordered_set <ll> s;
    while(x % 2 == 0) {
        s.insert(2);
        x /= 2;
    }

    for(ll i = 3 ; i <= sqrt(x) ; i++) {
        while(x % i == 0) {
            s.insert(i);
            x /= i;
        }
    }

    if(x > 1) {
        s.insert(x);
    }

    if(s.size() == 2) {
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 2 ; i <= n ; i ++) {
        if(check(i)) {
            ans ++;
        }
    }
    cout << ans << endl;

    return 0;
}
