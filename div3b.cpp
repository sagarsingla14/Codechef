#include <bits/stdc++.h>
using namespace std;
#include <vector>
#define ll long long int
#include <map>
#define mod 1000000007
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <pair <ll, ll> > v;
        for(ll i = 0 ; i < n ; i ++) {
            ll x , y;
            cin >> x >> y;
            v.push_back(make_pair(x , y));
        }

        sort(v.begin() , v.end());
        ll flag = 0;
        for(ll i = 0 ; i < v.size() - 1; i++) {
            if(v[i].second > v[i + 1].second) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            ll xx = 0, yy = 0;
            for(ll i = 0 ; i < v.size() ; i++) {
                ll xd = abs(v[i].first - xx);
                ll yd = abs(v[i].second - yy);
                string str = "";
                for(ll z = 0 ; z < xd ; z++) {
                    cout << "R";
                }
                for(ll z = 0 ; z < yd ; z++) {
                    cout << "U";
                }
                xx = v[i].first;
                yy = v[i].second;
            }
            cout << endl;
        }
    }
}
