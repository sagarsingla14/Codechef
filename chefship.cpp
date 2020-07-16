#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();

        ll j = n - 2;
        ll prev = j;
        map <ll , ll> mp;

        while(j >= 2) {
            ll i = n - 1;
            ll flag = 0;
            ll length = 0;

            ll slen = abs(i - j);
            while(i > j) {
                if(str[i] == str[prev]) {
                    i --;
                    length ++;
                    flag = 1;
                    prev --;
                }
                else{
                    break;
                }
            }
            if(length != slen) {
                flag = 0;
                length = 0;
            }
            if(flag) {
                mp[2 * length] = 1;
                j -= length;
            }
            else{
                j --;
            }
            prev = j;
        }

        ll ans = 0;

        reverse(str.begin() , str.end());
        // cout << str << endl;

        j = n - 2;
        prev = j;

        while(j >= 2) {
            ll i = n - 1;
            ll flag = 0;
            ll length = 0;
            ll slen = abs(i - j);
            while(i > j) {
                if(str[i] == str[prev]) {
                    i --;
                    length ++;
                    flag = 1;
                    prev --;
                }
                else{
                    break;
                }
            }

            if(length != slen) {
                flag = 0;
                length = 0;
            }
            if(flag) {
                if(mp[n - 2 * length]) {
                    ans ++;
                }
                j -= length;
            }
            else{
                j --;
            }
            prev = j;
        }

        cout << ans << endl;
    }
    return 0;
}
