#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , s;

bool big(ll x) {
    ll sd = 0;
    ll temp = x;
    while(temp) {
        sd += temp % 10;
        temp /= 10;
    }
    if(x - sd >= s) {
        return true;
    }
    else{
        return false;
    }
}

void solve() {
    ll mn = n;
    ll f = 1 , l = 1e18 ;
    ll minBigNum = n;
    while(f <= l) {
        ll m = f + ((l - f) / 2);
        if(big(m)) {
            minBigNum = m;
            l = m - 1;
        }
        else{
            f = m + 1;
        }
    }
    if(minBigNum == 1000000000000000000 && s == 1000000000000000000) {
        cout << 0 << endl;
        return ;
    }
    if(minBigNum > n) {
        cout << 0 << endl;
    }
    else{
        cout << abs(minBigNum - n) + 1 << endl;
    }
}

int main() {
    cin >> n >> s;
    solve();
    return 0;
}
