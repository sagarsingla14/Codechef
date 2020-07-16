#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll x , cnt = 0;
set <ll> ans;

void calcAnswer() {
    for(ll i = 1 ; i * i <= x ; i++) {
        ll f1 = __gcd(i , x);
        ll f2 = x / f1;
        ans.insert(f1);
        ans.insert(f2);
    }
    cout << ans.size() << endl;
}

int main() {
    cin >> x;

    calcAnswer();

    return 0;
}
