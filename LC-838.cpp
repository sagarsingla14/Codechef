#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


string solution(string str) {
    ll n = str.length();
    if(n <= 1) {
        return str;
    }

    ll r[n] = {0};
    ll l[n] = {0};

    ll cnt = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == 'R') {
            cnt = n;
            r[i] = cnt;
        }
        if(str[i] == '.') {
            r[i] = cnt;
        }
        cnt --;

        if(str[i] == 'L') {
            cnt = 0;
            r[i] = 0;
        }

        if(r[i] < 0) {
            r[i] = 0;
        }
    }

    cnt = 0;
    for(ll i = n - 1 ; i >= 0 ; i--) {
        if(str[i] == 'L') {
            cnt = n;
            l[i] = cnt;
        }
        if(str[i] == '.') {
            l[i] = cnt;
        }
        cnt --;
        if(str[i] == 'R') {
            cnt = 0;
            l[i] = 0;
        }

        if(l[i] < 0) {
            l[i] = 0;
        }
    }
    
    string s = "";
    for(ll i = 0 ; i < n ; i++) {
        if(r[i] == l[i]) {
            s += '.';
        }
        else if(r[i] > l[i]) {
            s += 'R';
        }
        else{
            s += 'L';
        }
    }
    return s;
}

int main() {
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}
