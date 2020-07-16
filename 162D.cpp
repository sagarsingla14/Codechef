#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
ll arr[100001] = {0};
ll dp[100001] = {0};
ll spf[100001] = {0};

void fillSpf() {
    for(ll i = 0 ; i <= 100000 ; i++) {
        spf[i] = i;
    }
    for(ll i = 2 ; i * i <= 100000 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j < 100001 ; j += i) {
                spf[j] = i;
            }
        }
    }
}

vector <ll> calcFac(ll val) {
    vector <ll> fac;
    while(val > 1) {
        fac.push_back(spf[val]);
        ll cur = spf[val];
        while(val % cur == 0) {
            val /= cur;
        }
    }
    return fac;
}



int main() {
    fast_io
    fillSpf();

    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    for(ll i = n ; i >= 1 ; i--) {
        vector <ll> fac = calcFac(arr[i]);
        ll mx = 0;
        for(auto itr : fac) {
            dp[itr] ++;
            mx = max(mx , dp[itr]);
        }
        for(auto itr : fac) {
            dp[itr] = mx;
        }
    }

    ll ans = 0;
    for(auto i : dp) {
        ans = max(ans , i);
    }

    if(ans != 0) {
        cout << ans << endl;
    }
    else {
        cout << 1 << endl;
    }

    return 0;
}
