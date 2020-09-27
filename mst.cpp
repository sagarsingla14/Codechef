#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m;
vector <pair <ll , pair <ll , ll>>> v;
ll rnk[1000] = {0};
ll parent[1000] = {0};
vector <ll> ans;

bool comp(pair <ll , pair <ll , ll>> a , pair <ll , pair <ll , ll>> b) {
    return a.second.second < b.second.second;
}

ll find(ll x) {
    if(x == parent[x]) {
        return x;
    }
    else{
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionbyRank(ll x , ll y, ll index) {
    ll xRep = find(x);
    ll yRep = find(y);
    if(xRep == yRep) {
        return ;
    }
    else{
        ans.push_back(index);
        if(rnk[xRep] > rnk[yRep]) {
            parent[yRep] = xRep;
        }
        else if(rnk[yRep] > rnk[xRep]) {
            parent[xRep] = yRep;
        }
        else{
            parent[yRep] = xRep;
            rnk[xRep] ++;
        }
    }
}

int main() {
    cin >> n >> m;

    for(ll i = 0 ; i < m ; i++) {
        ll x , y , w;
        cin >> x >> y >> w;
        v.push_back({x , {y , w}});
    }

    for(ll i = 0 ; i <= n ; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    sort(v.begin() , v.end() , comp);

    for(ll i = 0 ; i < m ; i++) {
        unionbyRank(v[i].first , v[i].second.first , i);
    }

    ll sum = 0;
    for(auto i : ans) {
        sum += v[i].second.second;
    }

    cout << sum << endl;
    return 0;
}
