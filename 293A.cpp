#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    ll n = a.length();
    string res = "";
    ll ans = 0;

    for(ll i = 0 ; i < n ; i++) {
        if(a[i] != 'z') {
            string s = "";
            for(ll j = 0 ; j < n ; j++) {
                if(j < i) {
                    s += a[j];
                }
                else if(j == i){
                    s += (a[j] + 1);
                }
                else{
                    s += 'a';
                }
            }
            if(s > a && s < b) {
                ans = 1;
                res = s;
                break;
            }
        }
    }

    if(ans) {
        cout << res << endl;
    }
    else{
        cout << "No such string" << endl;
    }
    return 0;
}
