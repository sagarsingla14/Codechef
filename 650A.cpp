#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();

        string s = "";
        s += str[0];
        for(ll i = 2 ; i <= n - 2 ; i += 2) {
            s += str[i];
        }

        s += str[n - 1];
        cout << s << endl;
    }
    return 0;
}
