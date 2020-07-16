#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        x ++;
        ll n;
        cin >> n;
        vector <pair <ll , ll> > v , op;
        for(ll i = 0 ; i < n ; i ++) {
            ll s , e;
            cin >> s >> e;
            v.push_back(make_pair(s , e));
            op.push_back(make_pair(s , e));
        }

        sort(v.begin() , v.end());

        ll assign[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            // assigned 1;
            ll flag = 0;
            if(assign[i] == 0) {
                flag = 1;
                assign[i] = 1;
                ll start = v[i].second;
                for(ll j = i + 1 ; j < n ; j++) {
                    if(v[j].first >= start && assign[j] == 0) {
                        start = v[j].second;
                        assign[j] = 1;
                    }
                }
            }
            if(flag) {
                break;
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            // assigned 2;
            ll flag = 0;
            if(assign[i] == 0) {
                flag = 1;
                assign[i] = 2;
                ll start = v[i].second;
                for(ll j = i + 1 ; j < n ; j++) {
                    if(v[j].first >= start && assign[j] == 0) {
                        start = v[j].second;
                        assign[j] = 2;
                    }
                }
            }
            if(flag) {
                break;
            }
        }

        ll impo = 0;
        for(ll i = 0 ; i < n ; i ++) {
            if(assign[i] == 0) {
                impo = 1;
                break;
            }
        }

        if(impo) {
            cout << "Case #" << x << ": IMPOSSIBLE" << endl;
        }
        else{
            vector <char> ans(n);
            for(ll i = 0 ; i < n ; i++) {
                pair <ll , ll> p = v[i];
                for(ll j = 0 ; j < n ; j++) {
                    if(p == op[j]) {
                        if(assign[i] == 1) {
                            ans[j] = 'C';
                        }
                        else if (assign[i] == 2){
                            ans[j] = 'J';
                        }

                        op[j].first = -1;
                        op[j].second = -1;
                        break;
                    }
                }
            }

            cout << "Case #" << x << ": ";
            for(ll i = 0 ; i < n ; i++) {
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}
