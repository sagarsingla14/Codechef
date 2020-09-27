#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
string a , b;
map <pair <string , ll> , ll> dp;

void calc(string str , ll index , ll cnt) {
    // rotate 2
    if(index == str.length()) {
        return;
    }

    calc(str , index + 1 , cnt);

}

ll solve(string a , string b) {
    calc(a , 0 , 0);

    ll ans = INT_MAX;
    for(auto i : mp) {
        if(i.first.first == b) {
            ans = min(ans , i.second);
        }
    }
    return ans;
}

int main() {
    cin >> a >> b;
    cout << solve(a , b) << endl;

    return 0;
}
