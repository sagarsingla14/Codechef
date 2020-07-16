#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        vector <string> str;
        for(ll i = 0 ; i < n ; i++) {
            string s;
            cin >> s;
            str.push_back(s);
        }
        sort(str.begin() ,  str.end());
        for(ll i = 0 ; i < n ; i++) {
            cout << str[i] << endl;
        }
        ll jump = k - 1;
        ll ans = 0;
        for(ll i = 0 ; i < n ; i+=jump) {
            // cout << str[i] << " " << str[i + jump] << endl;
            string s1 = str[i];
            string s2 = str[i + jump];
            ll cnt = 0;
            for(ll j = 0 ; j < s1.length() && j < s2.length() ; j++) {
                if(s1[j] != s2[j]) {
                    break;
                }
                else{
                    cnt ++;
                }
            }
            ans += cnt;
            i++;
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
 }
