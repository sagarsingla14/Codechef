#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while (t--) {
        vector <ll> v;
        ll a,b,c;
        cin >> a >> b>> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin() , v.end());
        ll mn = v[0];
        ll ans = mn;
        ll mx = v[2];
        ll diff = v[2] - v[1];
        if(diff >= mn) {
            ans += min(v[1] , v[2]);
        }
        else{
            mn = abs(mn - diff);
            v[2] = v[1];
            // ll sub = mn / 2;
            // v[1] -= sub;
            // v[2] -= sub;

            if(mn % 2) {
                ll sub = mn / 2 ;
                v[1] -= sub;
                v[1] --;
                v[2] -= sub;
            }
            else{
                ll sub = mn / 2 ;
                v[1] -= sub;
                v[2] -= sub;
            }
            ans += min(v[1] , v[2]);
        }
        cout << ans << endl;
    }
    return 0;
}
