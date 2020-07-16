#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll p = 31;
const ll mod = 1e9 + 7;

string str , bad;
in ans = 0;
in k , n;

ll hsh[101] = {0};
ll power[101] = {0};

void calcPower() {
    power[0] = 1;
    for(in i = 1 ; i < n ; i++) {
        power[i] = power[i - 1] * p;
        power[i] %= mod;
    }
}

void calcHash() {
    hsh[0] = 0;
    for(in i = 0 ; i < n ; i++) {
        ll curHash = ((str[i] - 'a' + 1) % mod) * ((power[i]) % mod);
        curHash %= mod;
        hsh[i + 1] = (curHash % mod + hsh[i] % mod) % mod;
    }
}

void findDistinctSubStrings() {
    set <ll> s;
    for(in l = 2 ; l <= 2 ; l++) {
        for(in i = 0 ; i <= n - l ; i++) {
            ll curHash = (hsh[i + l] - hsh[i] + mod) % mod;
            curHash *= (power[n - i - 1]);
            curHash %= mod;

            s.insert(curHash);
        }
    }

    cout << s.size() << endl;
}

void print() {
    cout << ans << endl;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        cin >> str;
        n = str.length();
        
        memset(hsh , 0 , sizeof(hsh));
        memset(power , 0 , sizeof(power));

        calcPower();
        calcHash();

        findDistinctSubStrings();
    }
    return 0;
}
