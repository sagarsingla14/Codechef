#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , ans = 0;
        cin >> n;

        string str;
        cin >> str;

        vector <ll> v(n , 0);
        for(ll i = 0 ; i < n ; i++) {
            v[i] = (str[i] - '0');
        }

        for(ll i = 0 ; i < n ; i++) {
            v[i] --;
        }

        map <ll , ll> mp;
        mp[0] ++;
        ll k = 0 , sum = 0;

        for(ll i = 0 ; i < n ; i++) {
            sum += v[i];
            if(mp[sum]) {
                ans += mp[sum];
            }
            mp[sum] ++;
        }

        cout << ans << endl;
    }
    return 0;
}
