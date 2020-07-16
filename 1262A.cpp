#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <pair <ll , ll>> v;
        ll temp = n;
        ll left = INT_MAX;
        while(temp--) {
            ll a , b;
            cin >> a >> b;
            v.push_back(make_pair(a , b));
        }
        sort(v.begin() ,  v.end());
        ll right = v[n-1].first;
        for(ll i = 0; i < n ; i++){
            left = min(left , v[i].second);
        }
        if(left >= right) {
            cout << 0 << endl;
        }
        else{
            cout << abs(left - right) << endl;
        }
    }
    return 0;
}
