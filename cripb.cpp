#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll n;
    cin >> n;
    string a , b;
    cin >> a >> b;
    ll k;
    cin >> k;

    ll check = 0;
    for(ll i = 2 ; i < n ; i++){
        string str = "";
        str += a;
        str += b;
        str += b;
        a = b;
        b = str;
    }

    if(b.length() < k) {
        cout << -1 << endl;
    }
    else{
        cout << b[k - 1] << endl;
    }
    return 0;
}
