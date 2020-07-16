#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        string str;
        cin >> n >> str;
        if(n == 2) {
            if(str[0] == str[1]) {
                cout << "YES" << endl << 0 << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        ll l = n / 2 - 1;
        ll ans = 0;
        ll impos = 0;
        ll swapped[n] = {0};
        for(ll i = 0 ; i <= n / 2 ; i++) {
            if(str[i] != str[n - 1 - i]) {
                if(str[n - 2 - i] == str[i] && swapped[n - 2 - i] == 0 && swapped[n - 1 - i] == 0) {
                    swapped[n - 2 - i] = 1;
                    swapped[n - 1 - i] = 1;
                    swap(str[n - 2 - i] , str[n - i - 1]);
                    ans ++;
                }
                else if (str[i + 1] == str[n - 1 - i] && swapped[i] == 0 && swapped[i + 1] == 0){
                    swap(str[i] , str[i + 1]);
                    swapped[i + 1] = 1;
                    swapped[i] = 1;
                    ans ++;
                }
                else {
                    impos = 1;
                    break;
                }
            }
        }

        for(ll i = 0 ; i <= n / 2 ; i ++) {
            if(str[i] != str[n - i - 1]) {
                impos = 1;
                break;
            }
        }
        if(impos) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl << ans << endl;
        }
    }
    return 0;
}
