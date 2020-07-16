#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define mod1 1000000009

ll p = 31;
ll p1 = 33;

set <pair <ll , ll>> s;

ll power[600001] = {0};
ll power1[600001] = {0};

void setPower() {
    power[0] = 1;
    for(ll i = 1 ; i <= 600000 ; i++) {
        power[i] = power[i - 1] % mod * p % mod;
        power[i] %= mod;
    }

    power1[0] = 1;
    for(ll i = 1 ; i <= 600000 ; i++) {
        power1[i] = power1[i - 1] % mod1 * p1 % mod1;
        power1[i] %= mod1;
    }
}

pair <ll , ll> calcHash(string str) {
    ll n = str.length();
    ll h = 0;
    for(ll i = 0 ; i < n ; i++) {
        h += (str[i] - 'a' + 1) % mod * power[i] % mod;
        h %= mod;
    }

    ll h1 = 0;
    for(ll i = 0 ; i < n ; i++) {
        h1 += (str[i] - 'a' + 1) % mod1 * power1[i] % mod1;
        h1 %= mod1;
    }
    return {h , h1};
}

int main() {
    fast_io
    setPower();
    ll n , q;
    cin >> n >> q;

    string arr[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        pair <ll , ll> h = calcHash(arr[i]);
        s.insert(h);
    }

    while(q--) {
        string str;
        cin >> str;
        pair <ll , ll> h = calcHash(str);
        ll found = 0;

        for(ll i = 0 ; i < str.length() ; i++) {
            char cur = str[i];
            for(char j = 'a' ; j <= 'c' ; j++) {
                if(j != cur) {
                    ll nHash = (h.first + mod - ((str[i] - 'a' + 1) * power[i] % mod) % mod + ((j - 'a' + 1) * power[i] % mod) % mod) % mod;
                    ll nHash1 = (h.second + mod1 - ((str[i] - 'a' + 1) * power1[i] % mod1) % mod1 + ((j - 'a' + 1) * power1[i] % mod1) % mod1) % mod1;
                    nHash %= mod;
                    nHash1 %= mod1;
                    if(s.find({nHash , nHash1}) != s.end()) {
                        found = 1;
                        break;
                    }
                }
            }
            if(found) {
                break;
            }
        }
        if(found) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
