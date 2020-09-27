#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void file_io() {
    freopen("alchemy_input.txt" , "r" , stdin);
    freopen("output3.txt", "w" , stdout);
}

int main() {
    file_io();
    ll t;
    cin >> t;
    for(ll c = 1 ; c <= t ; c ++) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        ll a = 0 , b = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == 'A') {
                a ++;
            }
            else{
                b ++;
            }
        }

        if(abs(a - b) == 1) {
            cout << "Case #" << c << ": " << "Y" << endl;
        }
        else{
            cout << "Case #" << c << ": " << "N" << endl;
        }
    }
    return 0;
}
