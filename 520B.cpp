#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll spf[1000001] = {0};
ll mx = 0 , mn = 1e10;
map <ll , ll> mp;
ll n;
ll ans = 0;

void sieve() {
    for(ll i = 0 ; i <= 1000000 ; i++) {
        spf[i] = i;
    }
    for(ll i = 2 ; i <= 1000000 ; i+= 2) {
        spf[i] = 2;
    }

    for(ll i = 3 ; i * i <= 1000000 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void calcFac() {
    ll val = n;
    while(val > 1) {
        ll f = spf[val];
        mp[f] ++;
        val /= f;
    }
}

void solve() {

    ll lg = ceil(log2(mx));
    lg = (1ll << lg);

    if(mx != lg) {
        ans ++;
    }
    else {
        if(mx > mn) {
            ans ++;
        }
    }
    ans += (log2(lg));
}

void print() {
    ll val = 1;
    for(auto i : mp) {
        val *= i.first;
    }

    cout << val << " " << ans << endl;
}

int main() {
    cin >> n;
    if(n == 1) {
        cout << "1 0" << endl;
        return 0;
    }

    sieve();
    calcFac();
    for(auto i : mp) {
        mx = max(mx , i.second);
        mn = min(mn , i.second);
    }
    
    solve();
    print();

    return 0;
}
