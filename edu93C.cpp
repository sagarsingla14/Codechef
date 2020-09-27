#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , ans = 0;
        cin >> n;
        string str;
        cin >> str;


        ll left[n] = {0};
        ll right[n] = {0};

        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                left[i] = 1;
            }
            else if(str[i] == '0') {
                left[i] = 0;
            }
            else{
                ll val = str[i] - '0';
                val --;
                ll ok = 1;

                if(i + val >= n) {
                    ok = 0;
                }
                for(ll j = i + 1 ; j <= i + val ; j ++) {
                    if(str[j] != '0') {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    left[i] = 1;
                }
                else{
                    left[i] = 0;
                }
            }
        }

        for(ll i = n - 1 ; i >= 0 ; i --) {
            if(str[i] == '0' || str[i] == '1') {
                right[i] = 0;
            }
            else{
                ll ok = 1;
                ll val = str[i] - '0';
                val --;
                if(i - val < 0) {
                    ok = 0;
                }
                for(ll j = i - 1 ; j >= i - val ; j --) {
                    if(str[j] != '0') {
                        ok = 0;
                    }
                }
                if(ok) {
                    right[i] = 1;
                }
                else{
                    right[i] = 0;
                }
            }
        }

        ll cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(left[i]) {
                cnt ++;
            }
            else {
                if(cnt) {
                    ans += (cnt * (cnt + 1)) / 2;
                }
                cnt = 0;
             }
        }
        if(cnt) {
            ans += (cnt * (cnt + 1)) / 2;
        }

        cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(right[i]) {
                cnt ++;
            }
            else {
                if(cnt) {
                    ans += (cnt * (cnt + 1)) / 2;
                }
                cnt = 0;
             }
        }
        if(cnt) {
            ans += (cnt * (cnt + 1)) / 2;
        }

        cout << ans << endl;
    }
    return 0;
}
