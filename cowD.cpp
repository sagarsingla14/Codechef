#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define MAXN 200001
#define level 18

vector <ll> graph[200001];
ll visited[200001];
ll levell[200001];
ll ok = 1;
unordered_map <ll , ll> mark;

ll depth[MAXN];
ll parent[MAXN][level];

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void ddfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<graph[cur].size(); i++)
    {
        if (graph[cur][i] != prev)
            ddfs(graph[cur][i], cur);
    }
}

void precomputeSparseMatrix(ll n)
{
    for (ll i=1; i<level; i++)
    {
        for (ll node = 1; node <= n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                    parent[parent[node][i-1]][i-1];
        }
    }
}

ll lca(ll u, ll v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    ll diff = depth[v] - depth[u];

    // Step 1 of the pseudocode
    for (ll i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];

    // now depth[u] == depth[v]
    if (u == v)
        return u;

    // Step 2 of the pseudocode
    for (ll i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}



void dfs(ll start , ll curlevel , ll p) {
    visited[start] = 1;
    levell[start] = curlevel;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , levell[start] + 1 , start);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n , q;
    cin >> n >> q;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u ,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1 , 1 , 1);

    ddfs(1,0);

    // Precomputing the 2^i th ancestor for evey node
    precomputeSparseMatrix(n);

    while(q--) {
        mark.clear();
        ll k;
        cin >> k;
        vector <ll> v(k);
        ll pos = 1;
        ll minLevel = 1e10;
        ll node = 0;
        unordered_map <ll , ll> mp;
        for(ll i = 0 ; i < k ; i++) {
            cin >> v[i];
            mp[levell[v[i]]] ++;
            if(minLevel > levell[v[i]]) {
                minLevel = levell[v[i]];
                node = v[i];
            }
        }

        if(mp[minLevel] == 1) {
            ok = 1;
            for(ll i = 0 ; i < k ; i++) {
                // cout << node << " " <<v[i] << endl;
                ll Lca = lca(node , v[i]);
                // cout << "lca " << Lca << endl;
                if(Lca != node) {
                    ok = 0;
                    break;
                }
            }

            if(!ok) {
                cout << -1 << endl;
            }
            else {
                cout << node << endl;
            }
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}

// #define MAXN 200001
//
// ll path[3][MAXN]; // storing root to node path
//
// // storing the path from root to node
// void ddfs(ll cur, ll prev, ll pathNumber, ll ptr,
    //                              ll node, bool &flag)
    // {
        //     for (ll i=0; i<graph[cur].size(); i++)
        //     {
            //         if (graph[cur][i] != prev and !flag)
            //         {
                //             // pushing current node llo the path
                //             path[pathNumber][ptr] = graph[cur][i];
                //             if (graph[cur][i] == node)
                //             {
                    //                 // node found
                    //                 flag = true;
                    //
                    //                 // terminating the path
                    //                 path[pathNumber][ptr+1] = -1;
                    //                 return;
                    //             }
                    //             ddfs(graph[cur][i], cur, pathNumber, ptr+1,
                        //                                         node, flag);
                        //         }
                        //     }
                        // }
                        //
                        // ll LCA(ll a, ll b)  {
                            //     // trivial case
                            //     if (a == b)
                            //         return a;
                            //
                            //     // setting root to be first element in path
                            //     path[1][0] = path[2][0] = 1;
                            //
                            //     // calculating path from root to a
                            //     bool flag = false;
                            //     ddfs(1, 0, 1, 1, a, flag);
                            //
                            //     // calculating path from root to b
                            //     flag = false;
                            //     ddfs(1, 0, 2, 1, b, flag);
                            //
                            //     // runs till path 1 & path 2 mathches
                            //     ll i = 0;
                            //     while (path[1][i] == path[2][i])
                            //         i++;
                            //
                            //     // returns the last matching node in the paths
                            //     return path[1][i-1];
                            // }
