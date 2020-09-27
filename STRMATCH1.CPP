#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , q;
string str;

unordered_map <ll , ll> mp;

void compute() {
    for(ll i = 0 ; i < n ; i++) {
        ll temp = 0;
        for(ll j = i ; j < n ; j++) {
            temp *= 29ll;
            temp += (str[j] - 'a' + 1);
            mp[temp] ++;
        }
    }
}

int main() {
    fast_io
    cin >> n >> q;
    cin >> str;

    compute();

    while(q--) {
        string s;
        cin >> s;
        ll curHash = 0;
        for(ll i = 0 ; i < s.length() ; i++) {
            curHash *= 29ll;
            curHash += (s[i] - 'a' + 1);
        }
        cout << mp[curHash] << endl;
    }
    return 0;
}
