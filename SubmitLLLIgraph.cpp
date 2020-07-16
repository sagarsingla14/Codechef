#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353
vector <ll> graph[2001];
ll visited[2001];
vector <ll> start;
ll checked[2001];
ll ans;
vector <ll> component;
ll compvisited[2001];
ll degree[2001];

bool sortBySec(pair <ll , ll> p1 , pair <ll , ll> p2) {
        return (p1.second < p2.second);
}

void findResForComp() {
    vector <pair <ll , ll> > v;
    for(ll i = 0 ; i < component.size() ; i++) {
        v.push_back(make_pair(component[i] , degree[component[i]]));
    }

    sort(v.begin() , v.end() , sortBySec);

    ll mx1 = 0;
    ll mx2 = 0;
    bool take1[2001];
    bool take2[2001];

    for(ll i = 0 ; i < component.size() ; i++) {
        ll count = 0;
        memset(take1 , true , sizeof(take1));
        memset(take2 , true , sizeof(take2));
        ll start = component[i];
        count ++;
        for(auto j : graph[start]) {
            take1[j] = false;
            take2[j] = false;
        }
        for(ll j = 0 ; j < v.size() ; j ++) {
            if(take1[v[j].first] && v[j].first != start) {
                count ++;
                for(auto k : graph[v[j].first]) {
                    take1[k] = false;
                }
            }
        }
        mx1 = max(mx1 , count);
        count = 0;
        for(ll j = v.size() - 1 ; j >= 0; j --) {
            if(take2[v[j].first] && v[j].first != start) {
                count ++;
                for(auto k : graph[v[j].first]) {
                    take2[k] = false;
                }
            }
        }
        mx2 = max(mx2 , count);
    }
    ll mx = max(mx1 , mx2);
    ans += mx;
    ans %= mod;
}

void findComponent(ll start) {
    memset(compvisited , 0 , sizeof(compvisited));
    component.push_back(start);
    compvisited[start] = 1;
    queue <ll> q;
    q.push(start);
    while(!q.empty()) {
        ll val = q.front();
        q.pop();
        for(auto j : graph[val]) {
            if(!compvisited[j]) {
                component.push_back(j);
                q.push(j);
                compvisited[j] = 1;
            }
        }
    }
}


void bfs(ll i) {
    visited[i] = 1;
    queue <ll> q;
    q.push(i);
    while(!q.empty()) {
        ll val = q.front();
        q.pop();
        for(auto j : graph[val]) {
            if(!visited[j]) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}


int main() {
    ans = 0;
    memset(visited , 0 , sizeof(visited));
    memset(checked , 0 , sizeof(checked));
    memset(degree , 0 , sizeof(degree));
    ll n , m , k;
    cin >> n >> m >> k;

    vector <pair <ll , ll>> vertex;
    vertex.push_back(make_pair(0 , 0));
    for(ll i = 1 ; i <= m ; i++) {
        ll u , v;
        cin >> u >> v;
        vertex.push_back(make_pair(u , v));
    }

    for(ll i = 1 ; i <= m ; i ++) {
        ll ux = vertex[i].first;
        ll vx = vertex[i].second;
        for(ll j = i + 1 ; j <= m ; j ++) {
            ll uy = vertex[j].first;
            ll vy = vertex[j].second;

            if(ux == uy || ux == vy || vx == uy || vx == vy) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                degree[j] ++;
                degree[i] ++;
            }
        }
    }

    for(ll i = 1 ; i <= m ; i++) {
        if(!visited[i]) {
            start.push_back(i);
            bfs(i);
        }
    }

    ans = 0;
    for(ll i = 0 ; i < start.size() ; i++) {
        component.clear();
        findComponent(start[i]);
        findResForComp();
    }

    cout << ans % mod << endl;

    return 0;
}
