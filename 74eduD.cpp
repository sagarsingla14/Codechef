#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll n , ans , cnt = 0;
string str;

int main() {
    fast

    cin >> n >> str;
    ans = (n * (n + 1)) / 2;
    ans -= n;

    cnt = 1;
    for(ll i = 1 ; i < n ; i++) {
        if(str[i] == 'A') {
            if(str[i - 1] == 'A') {
                cnt ++;
            }
            else{
                cnt = 1;
            }
        }
        else {
            if(str[i - 1] == 'A') {
                ans -= cnt;
                cnt = 1;
            }
        }
    }

    cnt = 1;
    reverse(str.begin() , str.end());
    for(ll i = 1 ; i < n ; i++) {
        if(str[i] == 'A') {
            if(str[i - 1] == 'A') {
                cnt ++;
            }
            else{
                cnt = 1;
            }
        }
        else {
            if(str[i - 1] == 'A') {
                ans -= cnt;
                cnt = 1;
            }
        }
    }

    cnt = 1;
    reverse(str.begin() , str.end());
    for(ll i = 1 ; i < n ; i++) {
        if(str[i] == 'B') {
            if(str[i - 1] == 'B') {
                cnt ++;
            }
            else{
                cnt = 1;
            }
        }
        else {
            if(str[i - 1] == 'B') {
                ans -= (cnt - 1);
                cnt = 1;
            }
        }
    }

    cnt = 1;
    reverse(str.begin() , str.end());
    for(ll i = 1 ; i < n ; i++) {
        if(str[i] == 'B') {
            if(str[i - 1] == 'B') {
                cnt ++;
            }
            else{
                cnt = 1;
            }
        }
        else {
            if(str[i - 1] == 'B') {
                ans -= (cnt - 1);
                cnt = 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
