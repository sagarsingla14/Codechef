// NUMBER OF DISTINCT SUBSTRINGS IN A STRING
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
string str;
const ll p = 31;
const ll mod = 1e9 + 7;
ll hsh[100001] = {0};
ll power[100001] = {0};

void solve() {
    ll dist = 0;
    for(ll l = 1 ; l <= n ; l++) {
        set <ll> s;
        cout << "length -> " << l << " -> ";
        for(ll i = 0 ; i <= n - l ; i++) {
            ll a = i;
            ll b = i + l;
            ll subhsh = (hsh[b] - hsh[a] + mod) % mod;
            subhsh *= power[n - i - 1];
            subhsh %= mod;
            cout << subhsh << " ";
            s.insert(subhsh);
        }
        cout << endl;
        dist += s.size();
    }
    cout << dist << endl;
}

void calcPower() {
    power[0] = 1;
    for(ll i = 1 ; i < n ; i++) {
        power[i] = power[i - 1] % mod * p % mod;
        power[i] %= mod;
    }
}

void calchsh() {
    hsh[0] = 0;
    for(ll i = 0 ; i < n ; i++) {
        hsh[i + 1] = hsh[i] % mod + (str[i] - 'a' + 1) * power[i] % mod;
    }

    for(ll i = 0 ; i <= n ; i++) {
        cout << hsh[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> str;

    calcPower();
    calchsh();
    solve();

    return 0;
}
