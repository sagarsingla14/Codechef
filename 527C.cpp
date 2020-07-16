#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll ans = 0;
ll n;

map <string , ll> mp;
map <string , ll> prefix , suffix;
vector <string> v , vv;

void solve(string str) {
    string s = "";
    for(ll i = 0 ; i < n - 1 ; i ++) {
        s += str[i];
        prefix[s] = 1;;
    }


    reverse(str.begin() , str.end());

    s = "";
    for(ll i = 0 ; i < n - 1 ; i ++){
        s += str[i];
        reverse(s.begin() , s.end());
        suffix[s] = 1;
        reverse(s.begin() , s.end());
    }

    for(auto i : vv) {
        if(prefix[i]) {
            cout << 'P';
            prefix[i] = 0;
        }
        else{
            cout << 'S';
        }
    }
    cout << endl;
}

bool check(string a , string b) {
    map <string , ll> cur = mp;
    string str = a;
    str += b[n - 2];

    string s = "";
    for(ll i = 0 ; i < n - 1 ; i++) {
        s += str[i];
        cur[s] --;
        if(cur[s] < 0) {
            return false;
        }
    }

    s = "";
    for(ll i = n - 1 ; i >= 1 ; i--) {
        s += str[i];
        reverse(s.begin() , s.end());
        cur[s] --;
        if(cur[s] < 0) {
            return false;
        }
        reverse(s.begin() , s.end());
    }

    return true;
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < (2 * n - 2) ; i++) {
        string s;
        cin >> s;
        if(s.length() == n - 1) {
            v.push_back(s);
        }
        vv.push_back(s);
        mp[s] ++;
    }

    string str = "";
    if(check(v[0] , v[1])) {
        str = v[0];
        str += v[1][n - 2];
    }
    else {
        str = v[1];
        str += v[0][n - 2];
    }

    solve(str);

    return 0;
}
