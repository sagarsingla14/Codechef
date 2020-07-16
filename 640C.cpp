#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll mul = k / (n - 1);
        ll rem = k % (n - 1);
        if(rem == 0) {
            rem = -1;
        }
        mul *= n;
        mul += rem;
        cout << mul << endl;
    }
    return 0;
}
