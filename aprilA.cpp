#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll mulltiples;

void countMul(ll n) {
    for(ll i = 2 ; i <= sqrt(n) ; i++) {
        while(n % i == 0) {
            n /= i;
            mulltiples ++;
        }
    }
    if(n > 1) {
        mulltiples ++;
    }
}

bool isprime(ll n) {
    bool prime = true;
    if(n == 1) {
        return false;
    }
    for(ll i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        mulltiples = 0;
        ll x , k;
        cin >> x >> k;
        countMul(x);
        if(k > mulltiples) {
            cout << 0 << endl;
        }
        else if(isprime(x)) {
            if(k == 1) {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}
