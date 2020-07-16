#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.size();
        ll cnt = 0;
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(str[i] != '0') {
                break;
            }
            else{
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
