#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lsb(ll val) {
    ll j = 0;
    ll found = 0;
    while(val && !found) {
        if((val & 1)) {
            break;
        }
        j++;
        val >>= 1;
    }
    return j;
}

int main() {
    train_choot_jayegi

    ll sum , least;
    cin >> sum >> least;
    vector <ll> ans;
    for(ll i = least ; i > 0 ; i--) {
        if(sum - power(2ll , lsb(i)) >= 0) {
            ans.push_back(i);
            sum -= power(2ll , lsb(i));
        }
        if(sum == 0) {
            break;
        }
    }
    if(sum == 0) {
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
