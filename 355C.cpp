#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll n , ans = 0;
map <char , ll> mp;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return res % mod;
}

void setMap() {
    ll value64 = 0;
    for(char i = '0' ; i <= '9' ; i++) {
        mp[i] = value64;
        value64 ++;
    }
    for(char i = 'A' ; i <= 'Z' ; i++) {
        mp[i] = value64;
        value64 ++;
    }
    for(char i = 'a' ; i <= 'z' ; i++) {
        mp[i] = value64;
        value64 ++;
    }
    mp['-'] = 62;
    mp['_'] = 63;
}

int main() {
    string str;
    cin >> str;
    n = str.length();
    setMap();

    ll cnt = 0;
    for(ll i = 0 ; i < n ; i ++) {
        char ch = str[i];
        ll chVal = mp[ch];
        for(ll j = 0 ; j < 6 ; j++) {
            if(!(chVal & (1 << j))) {
                cnt ++;
            }
        }
    }

    ans = power(3 , cnt) % mod;
    cout << ans % mod << endl;
    return 0;
}
