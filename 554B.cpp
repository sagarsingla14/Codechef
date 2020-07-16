#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll x , cnt = 0;
vector <ll> ans;

ll power(ll a , ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void calcAnswer() {
    cnt = 0;
    while(x != 1) {
        ll msb = log2(x);
        if(power(2 , msb + 1) - 1 == x) {
            break;
        }
        cnt ++;
        if(cnt & 1) {
            x ^= (power(2 , msb + 1) - 1);
            ans.push_back(msb + 1);
        }
        else {
            x ++;
        }
    }

    cout << cnt << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin >> x;

    calcAnswer();

    return 0;
}
