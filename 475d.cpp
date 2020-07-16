#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , q , x;
ll arr[100000];

unordered_map <ll , ll> ans;

void query() {
    cin >> x;
    cout << ans[x] << endl;
}

void computeRes() {
    unordered_map <ll , ll> cur , prev;
    for(ll i = 0 ; i < n ; i++) {
        cur.clear();
        if(i == 0) {
            cur[arr[i]] ++;
            ans[arr[i]] ++;
            prev.clear();
            prev = cur;
        }
        else{
            cur[arr[i]] ++;
            for(auto itr : prev) {
                ll g = __gcd(itr.first , arr[i]);
                cur[g] += itr.second;
            }

            for(auto itr : cur) {
                ans[itr.first] += itr.second;
            }
            prev.clear();
            prev = cur;
            cur.clear();
        }
    }
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    cin >> q;

    computeRes();

    while(q--) {
        query();
    }
    return 0;
}
