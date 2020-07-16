#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll t , n;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> n;
        vector <ll> v;
        ll sum = 0 , i = 0;
        while(sum + power(2ll , i) <= n) {
            v.push_back(power(2ll , i));
            sum += power(2ll , i);
            i ++;
        }
        if(sum != n) {
            v.push_back(n - sum);
        }

        sort(v.begin() , v.end());
        cout << v.size() - 1 << endl;
        for(ll i = 1 ; i < v.size() ; i++) {
            cout << abs(v[i] - v[i - 1]) << " ";
        }
        cout << endl;
    }

    return 0;
}
