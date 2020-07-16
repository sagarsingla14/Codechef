#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll x , n , ok;
bool isPrime[1000001];

void sieve() {
    for(ll i = 2 ; i * i <= 1000000 ; i ++) {
        if(isPrime[i]) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void checkPrime() {
    if(isPrime[x]) {
        ok = 1;
    }
    else {
        ok = 0;
    }
}

int main() {
    memset(isPrime , true , sizeof(isPrime));

    sieve();

    cin >> n;

    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 0 ; i < n ; i++) {
        cin >> x;
        ok = 1;
        ll num = sqrt(x);
        if(num * num == x) {
            x = sqrt(x);
            checkPrime();
            if(ok) {
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
