#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n;

int main() {
    fast_io
    cin >> n;
    string str[n];

    for(ll i = 0 ; i < n ; i++) {
        cin >> str[i];
    }

    map <string , ll> mp;
    for(ll i = n - 1 ; i >= 0 ; i --) {
        if(!mp[str[i]]) {
            cout << str[i] << endl;
            mp[str[i]] = 1;
        }
    }
    return 0;
}
