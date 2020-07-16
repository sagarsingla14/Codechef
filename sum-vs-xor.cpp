#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x ,ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y % 2) {
        return pw * pw * x;
    }
    else{
        return pw * pw;
    }
}

int main() {
    ll n;
    cin >> n;
    ll zeroBits = 0;
    while(n) {
        if(!(n & 1)) {
            zeroBits ++;
        }
        n >>= 1;
    }
    cout << power(2 , zeroBits) << endl;
    return 0;
}
