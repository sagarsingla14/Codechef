#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
ll ok = 0;
ll spf = 0;
void checkPrime() {
    ok = 1;
    for(ll i = 2 ; i * i <= n ; i++) {
        if(n % i == 0) {
            ok = 0;
            spf = i;
            break;
        }
    }
}

int main() {
    cin >> n;
    ok = 0;
    checkPrime();
    if(ok) {
        cout << 1 << endl;
    }
    else {
        cout << (n - spf) / 2 + 1 << endl;
    }
    return 0;
}
