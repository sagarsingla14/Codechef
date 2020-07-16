#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , a , b;
        cin >> n >> a >> b;
        string s = "";
        for(ll i = 0 ; i < a ; i++) {
            s += ('a' + (i % b));
        }
        ll mul = n / a;
        for(ll i = 0 ; i < mul ; i++) {
            cout << s;
        }
        ll rem = n % a;
        for(ll i = 0 ; i < rem ; i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
