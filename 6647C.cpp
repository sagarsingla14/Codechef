#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <vector <ll>> v;
ll n , x , y , t;

void solve(ll cd) {
    vector <ll> cur;
    ll cnt = n;
    cnt --;
    cur.push_back(y);
    ll temp = y;
    ll ok = 0;

    while(temp - cd >= 1 && cnt > 0) {
        cur.push_back(temp - cd);
        if(temp - cd == x) {
            ok = 1;
        }
        cnt --;
        temp -= cd;
    }

    temp = y;
    if(cnt) {
        while(cnt > 0) {
            cur.push_back(temp + cd);
            cnt --;
            temp += cd;
        }
    }

    if(ok) {
        // for(auto i : cur) {
        //     cout << i << " " ;
        // }
        // cout << endl;
        v.push_back(cur);
    }
}

int main() {

    cin >> t;
    while(t--) {
        cin >> n >> x >> y;

        if(n == 2) {
            cout << x << " " << y << endl;
            continue;
        }

        ll diff = abs(x - y);
        for(ll i = 1 ; i <= diff ; i++) {
            if(diff % i == 0) {

                // cout << " i " << i << endl;

                ll cd = diff / i;
                solve(cd);
            }
        }

        for(ll i = 0 ; i < v.size() ; i++) {
            sort(v[i].begin() , v[i].end());
        }

        ll mn = 100000000000000;
        for(ll i = 0 ; i < v.size() ; i++) {
            ll s = v[i].size();
            mn = min(mn , v[i][s - 1]);
        }

        vector <ll> ans;
        for(ll i = 0 ; i < v.size() ; i++) {
            ll s = v[i].size();
            if(mn == v[i][s - 1]) {
                ans = v[i];
                break;
            }
        }

        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;

        v.clear();
    }
    return 0;
}
