#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
string str;
ll ans , l;;

int main() {
    cin >> str;
    l = str.length();
    reverse(str.begin() , str.end());
    str += "-";
    ans = 0;
    for(ll i = 0 ; i < l ; i++) {
        if(str[i] == '0') {
            ans ++;
        }
        else if(str[i] == '1') {
            ll cnt = 0;
            ll j = i;
            while(str[j] == '1') {
                cnt ++;
                j ++;
            }
            if(i != l - 1) {
                str[j] = '1';
                ans += (cnt + 1);
                i = j;
                i --;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
