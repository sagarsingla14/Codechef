// implementation of Hopcroft Karp algorithm taken from geeksforgeeks

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
#define NIL 0
#define INF INT_MAX

vector <ll> graph[20001];
ll visited[20001];
vector <pair <ll , ll>> vertex;
vector <ll> start;
ll color;
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
    cout << "Vector -> " << endl;
    for(auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    ll mx = 0;
    bool take[2001];
    for(ll i = 0 ; i < component.size() ; i++) {
        ll count = 0;
        memset(take , true , sizeof(take));
        ll start = component[i];
        cout << "start " << start << endl << "Marked False -> ";
        for(auto j : graph[start]) {
            cout << j << " ";
            take[j] = false;
        }
        cout << endl;
        for(ll j = 0 ; j < v.size() ; j++) {
            ll vertex = v[j].first;
            cout << "vertex -> " << vertex << endl;
            if(take[vertex]) {
                count ++;
                for(auto k : graph[vertex]) {
                    take[k] = false;
                }
            }
        }
        cout << endl << "------" << endl;
        // cout << "Count -> " << count;
        mx = max(mx , count);
    }
    ans += mx;
    ans %= mod;
}

void freeRun() {
    for(ll i = 0 ; i < 10 ; i++) {
        ll x = 10;
    }
}

class BipGraph {
    ll m, n;

    list<ll> *adj;

    ll *pairU, *pairV, *dist;

public:
    BipGraph(ll m, ll n); // Constructor
    void addEdge(ll u, ll v); // To add edge

    bool bfs();

    bool dfs(ll u);

    ll hopcroftKarp();
};



void bfs(ll i) {
    visited[i] = color;
    queue <ll> q;
    q.push(i);
    while(!q.empty()) {
        ll val = q.front();
        color = visited[val];
        q.pop();
        for(auto j : graph[val]) {
            if(!visited[j]) {
                q.push(j);
                if(color == 1) {
                    visited[j] = 2;
                }
                else{
                    visited[j] = 1;
                }
            }
        }
    }
}


ll BipGraph::hopcroftKarp()
{
    pairU = new ll[m+1];
    pairV = new ll[n+1];

    dist = new ll[m+1];

    for (ll u=0; u<m; u++)
        pairU[u] = NIL;
    for (ll v=0; v<n; v++)
        pairV[v] = NIL;

    ll result = 0;

    while (bfs())
    {
        for (ll u=1; u<=m; u++)

            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}

bool BipGraph::bfs()
{
    queue<ll> Q; //an lleger queue

    for (ll u=1; u<=m; u++)
    {
        if (pairU[u]==NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }

        else dist[u] = INF;
    }

    dist[NIL] = INF;

    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();

        if (dist[u] < dist[NIL])
        {
            list<ll>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                ll v = *i;

                if (dist[pairV[v]] == INF)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
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


bool BipGraph::dfs(ll u)
{
    freeRun();
    
    if (u != NIL)
    {
        list<ll>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            ll v = *i;

            if (dist[pairV[v]] == dist[u]+1)
            {
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

BipGraph::BipGraph(ll m, ll n)
{
    this->m = m;
    this->n = n;
    adj = new list<ll>[m+1];
}

void BipGraph::addEdge(ll u, ll v)
{
    adj[u].push_back(v); // Add u to v’s list.
}

int main() {
    freeRun();
    ans = 0;
    memset(visited , 0 , sizeof(visited));
    memset(checked , 0 , sizeof(checked));
    memset(degree , 0 , sizeof(degree));

    color = 1;
    ll n , m , k;
    cin >> n >> m >> k;
    BipGraph g(m , m);
    freeRun();
    vertex.push_back(make_pair(0 , 0));
    for(ll i = 1 ; i <= m ; i++) {
        ll u , v;
        cin >> u >> v;
        vertex.push_back(make_pair(u , v));
    }
    freeRun();

    for(ll i = 1 ; i <= m ; i ++) {
        freeRun();
        ll ux = vertex[i].first;
        ll vx = vertex[i].second;
        for(ll j = i + 1 ; j <= m ; j ++) {
            ll uy = vertex[j].first;
            ll vy = vertex[j].second;

            if(ux == uy || ux == vy || vx == uy || vx == vy) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                g.addEdge(i , j);
                g.addEdge(j , i);
                degree[j] ++;
                degree[i] ++;
            }
        }
    }

    freeRun();

    for(ll i = 1 ; i <= m ; i++) {
        if(!visited[i]) {
            // start.push_back(i);
            // bfs(i);
        }
    }
    freeRun();

    cout << g.hopcroftKarp() / 2<< endl;

    return 0;
}
