#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n ;
    cin >> n;
    vector <string> str;
    map <string , ll> freq;
    for(ll i = 0 ; i < n ; i++) {
        cin >> str[i];
        freq[str[i]] ++;
    }
    sort(str.begin() , str.end());
    string ans = "";
    freq[ans] = 1;
    for(ll i = 0 ; i < n ; i++) {
        ll l = str[i].length();
        ll flag = 0;
        string s = "";
        s += str[i][0];
        if(freq[s]) {
            if(s.length() == ans.length()) {
                if(s < ans) {
                    ans = s;
                }
            }
            else if(s.length() > ans.length()) {
                ans = s;
            }
        }
        else{
            flag = 1;
            continue;
        }
        for(ll j = 1 ; j < l - 1 ; j++) {
            s += str[i][j];
            if(freq[s]) {
                if(s.length() == ans.length()) {
                    if(s < ans) {
                        ans = s;
                    }
                }
                else if(s.length() > ans.length()) {
                    ans = s;
                }
            }
            else{
                flag = 1;
                break;
            }
        }

        if(!flag) {
            if(str[i].length() == ans.length()) {
                if(s < ans) {
                    ans = str[i];
                }
            }
            else if(str[i].length() > ans.length()) {
                ans = str[i];
            }
        }
    }
    cout << ans << endl;


}
