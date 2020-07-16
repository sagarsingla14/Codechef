#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string str;
ll n;

bool check(ll sze) {
    char ss[3] = {0};
    for(ll i = 0 ; i < sze ; i++) {
        ss[str[i] - '1'] ++;
    }
    if(ss[0] && ss[1] && ss[2]) {
        return true;
    }
    ll j = sze;
    for(ll i = 1 ; i <= n - sze ; i++) {
        ss[str[i - 1] - '1'] --;
        ss[str[j] - '1'] ++;
        if(ss[0] && ss[1] && ss[2]) {
            return true;
        }
        j ++;
    }
    return false;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> str;
        unordered_set <char> s;
        for(ll i = 0 ; i < str.length() ; i++) {
            s.insert(str[i]);
        }

        if(s.size() < 3) {
            cout << 0 << endl;
        }
        else {
            n = 0;
            n = str.length();
            ll ans = 0;
            ll f = 1 , l = n;
            ll mid = 0;

            while(f <= l) {
                mid = (f + l) / 2;
                if(check(mid)) {
                    l = mid - 1;
                    ans = mid;
                }
                else{
                    f = mid + 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
