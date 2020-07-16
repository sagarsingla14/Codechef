#include <bits/stdc++.h>
using namespace std;
#include <vector>
#define ll long long int
#include <map>
#define mod 1000000007
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll aa = -1 , bb = -1 , cc = -1;
        for(ll i = 2 ; i <= cbrt(n); i++) {
            ll flag = 0;
            if(n % i == 0) {
                for(ll j  = 2 ; j <= sqrt(n / i) ; j++) {
                    if(n % j == 0) {
                        ll c = n / i;
                        c /= j;

                        if(i * j * c == n && c != 1 && i != j && j != c && c != i ) {
                            aa = i;
                            bb = j;
                            cc = c;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) {
                    break;
                }
            }
        }

        // cout << aa << " " << bb << " " << cc << endl;
        if(aa == -1 || bb == -1 || cc == -1) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << aa << " " << bb << " " << cc << endl;
        }
    }
    return 0;
}
