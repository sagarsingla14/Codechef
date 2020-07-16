#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        string str;
        cin >> str;
        string s = str;

        ll cnt = 0;
        ll one = 0;
        ll index = 0;

        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one ++;
            }
            if(one == 1 && str[i] == '1') {
                index = i;
            }
        }

        ll ans = 0;
        if(one != 0) {
            cnt = 0;
            for(ll i = index ; i < n ; i++) {
                if(str[i] == '1') {
                    ll num = (cnt - k);
                    num /= (k + 1);
                    if(num >= 0) {
                        ans += num;
                    }
                    cnt = 0;
                }
                else {
                    cnt ++;
                }
            }

            // cout << ans << endl;

            ans += (cnt / (k + 1));

            cnt = 0;
            for(ll i = index ; i >= 0 ; i--) {
                if(str[i] == '1') {
                    cnt = 0;
                }
                if(str[i] == '0') {
                    cnt ++;
                    if(cnt > k) {
                        ans ++;
                        cnt = 0;
                    }
                }
            }

            cout << ans << endl;
        }
        else {
            k ++;

            ll div = n / k;
            if(n % k) {
                div ++;
            }
            cout << div << endl;
        }
    }
    return 0;
}
