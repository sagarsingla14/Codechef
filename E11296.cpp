#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    string str;
    cin >> n >> str;
    string ans = "";
    char prev0 = 'a' , prev1 = 'a';
    ll flag = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] >= prev0) {
            prev0 = str[i];
            ans += '0';
        }
        else if(prev1 <= str[i]) {
            prev1 = str[i];
            ans += '1';
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag) {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl << ans << endl;
    }
    return 0;
}
