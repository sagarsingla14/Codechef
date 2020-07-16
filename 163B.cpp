#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main() {
    ll n , t;
    cin >> n >> t;
    string str;
    cin >> str;
    for(ll i = 0 ; i < t ; i++) {
        for(ll i = 1 ; i < n ; i++) {
            if(str[i] == 'G' && str[i - 1] == 'B') {
                str[i - 1] = 'G';
                str[i] = 'B';
                i ++;
            }
        }
    }
    cout << str << endl;
    return 0;
}
