#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        if(n == 1 || m == 1) {
            cout << "YES" << endl;
        }
        else if(n == 2 && m == 2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
