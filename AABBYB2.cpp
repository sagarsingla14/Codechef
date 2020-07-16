#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
ll ok = 1 , ans = 0;

set <ll> s;
void checkPrime() {
    ok = 1;
    for(ll i = 2 ; i * i <= n ; i++) {
        if(n % i == 0) {
            ok = 0;
            s.insert(n / i);
            s.insert(i);
        }
    }
}

void calcAnswer() {
    for(auto i : s) {
        while(n % i == 0) {
            ans += n;
            n /= i;
        }
    }
    ans ++;
    cout << ans << endl;
}

int main() {
    cin >> n;
    checkPrime();
    if(ok) {
        cout << n + 1 << endl;
    }
    else {
        calcAnswer();
    }
}
