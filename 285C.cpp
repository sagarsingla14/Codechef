// 10
// 3 13
// 2 6
// 1 5
// 3 5
// 1 3
// 2 2
// 2 6
// 1 6
// 1 3
// 2 3

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    cin >> n;

    vector <pair <ll , ll> > v;
    queue <pair<ll , ll> > q;

    for(ll i = 0 ; i < n ; i++) {
        ll d , s;
        cin >> d >> s;
        v.push_back(make_pair(d , s));
        if(d == 1) {
            q.emplace(i , s);
            // cout << "i d s " << i << " " << d << " " << s << endl;
        }
    }

    vector <pair <ll , ll> > ans;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        ll curLeaf = p.first;
        ll leafParent = p.second;
        if(v[curLeaf].first == 0) {
            continue;
        }
        ans.push_back(make_pair(leafParent , curLeaf));
        v[leafParent].first --;
        v[leafParent].second ^= curLeaf;
        if(v[leafParent].first == 1) {
            q.emplace(leafParent , v[leafParent].second);
            // cout << "i d s " << v[parent].first << " " << v[parent].second << endl;
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
