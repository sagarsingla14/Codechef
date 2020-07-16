#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll ans = 0;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ans = 0;
        ll n , x;
        cin >> n >> x;
        string str;
        cin >> str;
        ll one = 0 , zero = 0;
        for(auto i : str) {
            if(i == '0') {
                zero ++;
            }
            else{
                one ++;
            }
        }

        ll diff = zero - one;
        if(diff == 0) {
            ll found = 0;
            for(auto i : str) {
                if(i == '0') {
                    ans ++;
                }
                else {
                    ans --;
                }

                if(ans == x) {
                    found = 1;
                    break;
                }
            }

            if(found) {
                cout << -1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else{
            ll div = x / diff;
            div --;

            str += str;
            str += str;
            str += str;

            ll val = div * diff;
            if(val == x) {
                ans ++;
            }
            for(auto i : str) {
                if(i == '1') {
                    val --;
                }
                else {
                    val ++;
                }
                if(val == x) {
                    ans ++;
                }
            }
            cout << ans << endl;

        }
    }
    return 0;
}
