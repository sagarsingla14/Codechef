#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x , y , z;
        cin >> x >> y >> z;
        map <ll , ll> mp;

        ll mx = 0;
        mx = max(x , y);
        mx = max(mx , z);

        ll mn = min(x , y);
        mn = min(mn , z);
        mp[x] ++;
        mp[y] ++;
        mp[z] ++;

        if(mp[mx] >= 2) {
            cout << "YES" << endl;
            cout << mn << " " << mn << " " << mx << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
