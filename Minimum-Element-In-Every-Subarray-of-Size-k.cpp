#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll arr[100001] = {0};
ll n , q;

void solve(ll x) {

    vector <ll> ans;
    deque <pair <ll , ll>> q;

    for(ll i = 0 ; i < x ; i++) {
        while(!q.empty() && (q.back().first) < arr[i]) {
            q.pop_back();
        }

        q.push_back({arr[i] , i});
    }

    ans.push_back(q.front().first);

    for(ll i = x ; i < n ; i++) {
        while(!q.empty() && (q.front()).second <= (i - x)) {
            q.pop_front();
        }
        while(!q.empty() && (q.back().first) < arr[i]) {
            q.pop_back();
        }
        q.push_back({arr[i] , i});
        ans.push_back(q.front().first);
    }


    ll res = 1e10;
    for(auto i : ans) {
        res = min(res , i);
    }
    cout << res << endl;
}

int main() {
    cin >> n >> q;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    while(q --) {
        ll x;
        cin >> x;
        solve(x);
    }
    return 0;
}
