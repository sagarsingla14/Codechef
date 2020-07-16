#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll p = 31;
const ll mod = 1e9 + 7;

string str , pat;
ll power[1000001] = {0};
ll hsh[1000001] = {0};
ll t , sl = 0 , pl = 0 , patHash = 0;
vector <ll> res;

void calcPower() {
    power[0] = 1;
    for(ll i = 1 ; i <= 1000000 ; i++) {
        power[i] = power[i - 1] * p;
        power[i] %= mod;
    }
}

void hashString() {
    for(ll i = 0 ; i < sl ; i++) {
        hsh[i + 1] = (hsh[i] + (str[i] - 'a' + 1) * power[i]) % mod;
        hsh[i + 1] %= mod;
    }
}

void hashpattern() {
    patHash = 0;
    for(ll i = 0 ; i < pl ; i++) {
        patHash += ((pat[i] - 'a' + 1) * power[i]) % mod;
        patHash %= mod;
    }
}

void Rabin_Karp() {
    for(ll i = 0 ; i <= sl - pl ; i++) {
        ll curHash = (hsh[i + pl] - hsh[i] + mod) % mod;
        if(curHash == ((power[i] * patHash) % mod)) {
            res.push_back(i + 1);
        }
    }
}

void printAns() {
    ll ans = res.size();
    if(ans == 0) {
        cout << "Not Found" << endl;
    }
    else{
        cout << ans << endl;
        for(auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    res.clear();
    cout << endl;
}

int main() {
    cin >> t;
    calcPower();
    while(t--) {
        cin >> str >> pat;

        sl = str.length();
        pl = pat.length();

        patHash = 0;

        hashString();
        hashpattern();
        Rabin_Karp();
        printAns();
    }

    return 0;
}
