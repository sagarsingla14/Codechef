#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000


int ok = 0;

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        ld d;
        ok = 0;
        cin >> n >> d;

        ld arr[n] = {0};
        vector <pair <ld , ld>> v;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            v.push_back({arr[i] + d , arr[i]});
        }
        sort(v.begin() , v.end());

        for(ll i = 0 ; i < n ; i++) {
            swap(v[i].first , v[i].second);
            cout << v[i].first << " " << v[i].second << endl;
        }

        ld l = 0 , r = 2000000000;

        ld ans = 0;
        while(l <= r) {
            ld mid = (l + r) / 2.0;

            ok = 1;
            for(ll i = 0 ; i < n ; i++) {
                ld diff = v[i].second - v[0].first + 1.0;
                ld val = diff / mid;

                if(val <= i) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                l = mid + 0.0000001;
                ans = mid;
            }
            else{
                r = mid - 0.0000001;
            }
        }

        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
