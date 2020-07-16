#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
void type2() {
    ll node = 2;
    for(ll i = 0 ; i < n - 2 ; i++) {
        cout << i + 1 << " " << i + 2 << endl;
    }
    cout << 1 << " " << n << endl;
}
void type1() {
    ll node = 2;
    for(ll i = 0 ; i < n - 1 ; i++) {
        cout << 1 << " " << node << endl;
        node ++;
    }
}

int main() {
    cin >> n;
    if(n == 2 || n == 3) {
        cout << -1 << endl;
        type1();
    }
    else{
        type2();
        type1();
    }
    return 0;
}
