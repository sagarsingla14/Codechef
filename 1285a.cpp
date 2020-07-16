#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll l = 0 , r = 0;
    for(ll i = 0 ; i < str.length() ; i ++) {
        if(str[i] == 'L') {
            l ++;
        }
        else{
            r++;
        }
    }

    l *= -1;

    cout << abs(l - r) + 1 << endl;
    return 0;
}
