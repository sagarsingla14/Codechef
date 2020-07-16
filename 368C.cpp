#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , x , y , pw;

ll power(ll a , ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    if(n <= 2) {
        cout << -1 << endl;
    }
    else{
        pw = power(n , 2ll);
        if(n & 1) {
            x = (pw + 1) / 2;
            y = (pw - 1) / 2;
        }
        else{
            x = (pw / 4 + 1);
            y = (pw / 4 - 1);
        }
        cout << y << " " << x << endl;
    }

    return 0;
}
