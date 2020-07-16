#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , m;
    cin >> n >> m;
    ll val = abs(m - n)/2;
    if(abs(m - n) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    if(m == 0) {
        cout << 0 << endl;
        return 0;
    }
    if(n == m) {
        cout << 1 << endl << n << endl;
        return 0;
    }
    if(n > m){
        cout << -1 << endl;
        return 0;
    }
    if((n & val)) {
        cout << 3 << endl << n <<" "<< val << " " << val << endl;
    }
    else{
        cout << 2 << endl << n + val << " " << val << endl;
    }
    return 0;
}
