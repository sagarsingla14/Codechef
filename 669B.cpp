#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);

        vector <ll> v;
        ll visited[n] = {0};

        ll mx = arr[n - 1];
        visited[n - 1] = 1;

        v.push_back(mx);
        ll g = mx;


        for(ll j = 0 ; j < n - 1 ; j ++) {
            vector <pair <ll , ll>> cur;

            ll index = -1;
            mx = 0;

            for(ll i = 0 ; i < n - 1 ; i++) {
                if(!visited[i]) {
                    cur.push_back({__gcd(g , arr[i]) , i});
                }

                for(auto i : cur) {
                    if(i.first >= mx) {
                        index = i.second;
                        mx = i.first;
                    }
                }

            }
            g = __gcd(g , mx);
            v.push_back(arr[index]);
            visited[index] = 1;
        }

        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
