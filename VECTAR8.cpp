#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isPrime[1000001];
vector <ll> primes;
vector <ll> primesNoZero;

void sieve() {
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 2 ; i <= 1000000 ; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

bool check(ll x) {
    bool res = true;
    string s = "";
    while(x) {
        s += '0' + x % 10;
        if(x % 10 == 0) {
            res = false;
            break;
        }
        x /= 10;
    }

    reverse(s.begin() , s.end());
    for(ll i = 0 ; i < s.length() ; i++) {
        ll num = 0;
        for(ll j = i ; j < s.length() ; j++) {
            num *= 10;
            num += (s[j] - '0');
        }

        if(!isPrime[num]) {
            res = false;
            break;
        }
    }

    return res;
}

void calcSafePrime() {
    for(auto i : primes) {
        if(check(i)) {
            primesNoZero.push_back(i);
        }
    }
}

int main() {
    memset(isPrime , true , sizeof(isPrime));
    sieve();
    calcSafePrime();

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        auto index = lower_bound(primesNoZero.begin() , primesNoZero.end() , n) - primesNoZero.begin();
        if(primesNoZero[index] == n) {
            index ++;
        }
        cout << index << endl;
    }
    return 0;
}
