#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , ok = 0;
ll spf[1001];
vector <ll> ans;

void sieve() {
    for(ll i = 1 ; i <= 1000 ; i ++) {
        spf[i] = i;
    }

    for(ll i = 2 ; i * i <= 1000 ; i ++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 1000 ; j += i) {
                spf[j] = i;
            }
        }
    }
}

void calcFactor(ll x) {
    set <ll> s;
    while(x > 1) {
        ll fac = spf[x];
        x /= fac;
        s.insert(fac);
    }

    if(s.size() <= 1) {
        ok = 1;
    }
}

void calcAnswer() {
    for(ll i = 2 ; i <= n ; i++) {
        ok = 0;
        calcFactor(i);
        if(ok) {
            ans.push_back(i);
        }
    }
}

int main() {
    memset(spf , 0 , sizeof(spf));
    sieve();

    cin >> n;

    calcAnswer();

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
