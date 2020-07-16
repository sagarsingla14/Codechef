#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
int main() {
    ll x , s;
    cin >> x >> s;
    if(x == 0) {
        if(s == 0) {
            cout << "0" << endl;
        }
        else{
            if(s % 2 == 0) {
                cout << 2 << endl;
                cout << s /2 << " " << s / 2 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    if(x == 1) {
        if(s % 2) {

        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
