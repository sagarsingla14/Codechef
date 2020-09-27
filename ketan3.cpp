#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll calc(string str) {
    ll w = 0;
    for(auto i : str) {
        w += (i - 'a' + 1);
    }
    return w;
}

static bool comp(pair <string , ll> &a , pair <string , ll> b) {
    return a.second < b.second;
}

int main() {
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        string arr[n];

        set <string> s;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        if(s.size() == 1) {
            for(auto i : s) {
                cout << i << " " ;
            }
            cout << endl;
            continue;
        }

        vector <pair <string , ll>> v;
        for(ll i = 0 ; i < n ; i++) {
            ll w = calc(arr[i]);
            v.push_back({arr[i] , w});
        }

        sort(v.begin() , v.end() , comp);

        // taking max;
        ll sumMax = 0;
        for(ll i = 1 ; i < n ; i++) {
            sumMax += v[i].second;
        }
        sumMax /= (n - 1);

        ll cnt0 = 0 , cnt1 = 0;
        for(ll i = 1 ; i < n ; i++) {
            cnt0 += (abs(v[i].second - sumMax));
            cnt1 += (abs(v[i].second - (sumMax + 1)));
        }

        ll mxMin = min(cnt0 , cnt1);

        // taking min
        ll sumMin = 0;
        for(ll i = 0 ; i < n - 1 ; i++) {
            sumMin += v[i].second;
        }
        sumMin /= (n - 1);

        cnt0 = 0 , cnt1 = 0;
        for(ll i = 0 ; i < n - 1 ; i++) {
            cnt0 += (abs(v[i].second - sumMin));
            cnt1 += (abs(v[i].second - (sumMin + 1)));
        }

        ll mnMin = min(cnt0 , cnt1);
        if(mnMin > mxMin) {
            cout << v[0].first << endl;
        }
        else{
            cout << v[n - 1].first << endl;
        }
    }
    return 0;
}
