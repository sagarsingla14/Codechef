#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string callString(string str , ll n ,  ll k) {
    string prefix = str.substr(k , n);
    string suffix = str.substr(0 , k);
    ll spaceleft = abs(n - k);
    if(k % 2 != n % 2) {
        reverse(suffix.begin() , suffix.end());
    }
    return prefix + suffix;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        string str;
        cin >> n >> str;
        ll k = 1;
        string ans = str;
        for(ll i = 2 ; i <= n ; i++) {
            string temp = callString(str , n , i - 1);
            if(temp < ans) {
                ans = temp;
                k = i;
            }
        }
        cout << ans << endl << k << endl;
    }
    return 0;
}
