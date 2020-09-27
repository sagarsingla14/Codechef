#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , t;
ll phi[1000001] = {0};
ll spf[1000001] = {0};
map <ll , ll> mp;

void phiCalc() {
    phi[1] = 1;
    for(ll i = 0 ; i <= 1000000; i++) {
        phi[i] = i;
    }

    for(ll i = 2 ; i <= 1000000 ; i ++) {
        if(phi[i] == i) {
            for(ll j = i ; j <= 1000000 ; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

void sieve() {
	spf[1] = 1;
	for(ll i = 2; i <= 1000000 ; i++) {
        spf[i] = i;
    }
	for(ll i = 4 ; i <= 1000000 ; i += 2) {
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

void calcSumExp() {
    mp[1] = 0;
    for(ll i = 2 ; i <= 1000000 ; i++) {
        ll cnt = 0;
        ll num = i;
        while(num > 1) {
            num /= spf[num];
            cnt ++;
        }
        mp[i] = cnt;
    }
}

ll b(ll num) {
    ll cnt = 0;

    if(num == 1) {
        return 1;
    }

    set <ll> s;
    for(ll i = 1 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) {
            s.insert(i);
            s.insert(num / i);
        }
    }

    for(auto i : s) {
        cnt += phi[i];
    }

    return cnt;
}

ll c(ll num) {
    ll x = b(num);
    return mp[x];
}


int main() {
    phiCalc();
    sieve();
    calcSumExp();

    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(ll i = 1 ; i <= n ; i++) {
            ans += c(i);
        }
        cout << ans << endl;
    }

    return 0;
}
