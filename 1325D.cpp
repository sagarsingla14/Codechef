#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll xr , sum;
    cin >> xr >> sum;
    ll diff = abs(xr - sum);
    if(xr > sum) {
        cout << -1 << endl;
    }
    else if(xr == sum && xr != 0){
        cout << 1 << endl << xr << endl;
    }
    else if(xr == 0 && sum == 0){
        cout << 0 << endl;
    }
    else if(diff % 2) {
        cout << -1 << endl;
    }
    else{
        ll x = diff / 2;
        // cout << xr <<" " << x << " " << (xr & x) << endl;
        if((xr & x) == 0) {
            cout << 2 << endl << xr + x << " " << x << endl;
        }
        else {
            cout << 3 << endl << xr << " " << x << " " << x << endl;;
        }
    }
    return 0;
}
