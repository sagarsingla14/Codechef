#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

string calc(string str) {
    ll n = str.length();
    if(n & 1) {
        return str;
    }

    string a = "" , b = "";
    for(ll i = 0 ; i < n / 2 ; i++) {
        a += str[i];
    }
    for(ll i = n / 2 ; i < n ; i++) {
        b += str[i];
    }
    a = calc(a);
    b = calc(b);

    if(a < b) {
        return a + b;
    }
    else{
        return b + a;
    }
}

int main() {
    string a , b;
    cin >> a >> b;
    a = calc(a);
    b = calc(b);
    if(a == b) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
