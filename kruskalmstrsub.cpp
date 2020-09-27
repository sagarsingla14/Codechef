#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m , ans;
vector <pair <pair <ll , ll> , ll> > v;

ll parent[100001];
ll rnk[100001];

void make_Set() {
    for(ll i = 0 ; i <= n ; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

void Union(ll x , ll y) {
    ll xp = parent[x];
    ll yp = parent[y];

    if(rnk[xp] > rnk[yp]) {
        parent[yp] = xp;
    }
    else if(rnk[xp] < rnk[yp]) {
        parent[xp] = yp;
    }
    else{
        parent[y] = xp;
        rnk[xp] ++;
    }
}

ll findParent(ll x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        ll rep = findParent(parent[x]);
        return rep;
    }
}


void kruskals() {
    make_Set();
    for(ll i = 0 ; i < v.size() ; i++) {
        pair <ll , ll> p = v[i].first;
        ll x = p.first;
        ll y = p.second;

        ll xp = findParent(x);
        ll yp = findParent(y);

        if(xp != yp) {
            ans += v[i].second;
            Union(x , y);
        }
    }
}

bool comp(pair <pair <ll , ll> , ll> a , pair <pair <ll , ll> , ll> b) {
    return a.second < b.second;
}

int main() {
    cin >> n >> m;

    for(ll i = 0 ; i < m ; i ++) {
        ll x , y , wt;
        cin >> x >> y >> wt;
        pair <ll , ll> p = make_pair(x , y);
        pair <pair <ll , ll> , ll> pp = make_pair(p , wt);
        v.push_back(pp);
    }

    sort(v.begin() , v.end() , comp);

    ans = 0;
    memset(parent , 0 , sizeof(parent));
    memset(rnk , 0 , sizeof(rnk));
    kruskals();

    cout << ans << endl;
    return 0;
}
