#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector <vector <pair <ll , ll> > > factor(1001);
ll isPrime[1000001];
ll n;
ll mp[1000001];
ll d[1001];
ll p[1001][18];
vector <ll> graph[1001];
vector <ll> timeStamp;
ll currentTime;
vector < vector <ll> > checktime(1001);

void calcfactor(ll arr[]) {
    // Checked
    for(ll i = 1 ; i <= n ; i++) {
        unordered_map <ll , ll> m;
        ll term = arr[i];
        while(term != 1) {
            if(m.find(isPrime[term]) == m.end()) {
                m[isPrime[term]] = 1;
            }
            else{
                m[isPrime[term]] ++;
            }

            term /= isPrime[term];
        }

        for(auto j : m) {
            factor[i].push_back(j);
        }
    }
}

void sieve() {
    // Checked
    for(ll i = 2 ; i * i <= 1000000 ; i++) {
        if(isPrime[i] == 0) {
            isPrime[i] = i;
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                isPrime[j] = i;
            }
        }
    }
    for(ll i = 2 ; i <= 1000000 ; i++) {
        if(isPrime[i] == 0) {
            isPrime[i] = i;
        }
    }
}

void precomp() {
    for(ll i = 1; i < 18 ; i++) {
        for(ll node = 1; node <= n; node++) {
            if(p[node][i - 1] != -1) {
                p[node][i] = p[p[node][i-1]][i-1];
            }
        }
    }
}


void dfs(ll cur, ll prev) {
    currentTime ++;
    d[cur] = d[prev] + 1;
    timeStamp.push_back(cur);
    checktime[cur].push_back(currentTime);

    p[cur][0] = prev;
    for (ll i = 0; i < graph[cur].size(); i++) {
        if(graph[cur][i] != prev) {
            dfs(graph[cur][i] , cur);
        }
    }
    currentTime ++;
    checktime[cur].push_back(currentTime);
    timeStamp.push_back(cur);
}


ll LCA(ll u , ll v) {
    if(d[v] < d[u]) {
        swap(u, v);
    }
    ll diff = d[v] - d[u];
    for(ll i = 0; i < 18; i++) {
        if((diff >> i) % 2 == 1) {
            v = p[v][i];
        }
    }
    if (u == v) {
        return u;
    }
    for(ll i = 17; i >= 0; i--) {
        if(p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
// 5
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6 4 3 5
// 2
// 1 4
// 2 2
ll calcAnswer(vector <ll> path) {
    unordered_set <ll> s;
    unordered_map <ll , ll> mp;
    for(ll i = 0 ; i < path.size() ; i++) {
        ll vertex = path[i];
        for(ll j = 0 ; j < factor[vertex].size() ; j++) {
            ll primeNum = factor[vertex][j].first;
            ll primeNumPower = factor[vertex][j].second;
            mp[primeNum] += primeNumPower;
            s.insert(primeNum);
        }
    }

    ll ans = 1;
    for(auto itr : s) {
        ll divisors = (mp[itr] + 1);
        mp[itr] = 0;
        ans *= divisors;
        ans %= mod;
    }
    return ans % mod;
}

int main() {

    memset(isPrime , 0 , sizeof(isPrime));
    memset(mp , 0 , sizeof(mp));
    sieve();

    ll t;
    cin >> t;
    while(t--) {

        currentTime = 0;
        timeStamp.clear();
        timeStamp.push_back(0);
        cin >> n;
        for(ll i = 0 ; i < n - 1 ; i++) {
            ll a , b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset(p , -1 , sizeof(p));
        memset(d , 0 , sizeof(d));
        d[0] = 0;
        dfs(1 , 0);
        precomp();

        ll arr[n + 1];
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }
        calcfactor(arr);
        ll q;
        cin >> q;
        while(q--) {
            ll u , v;
            cin >> u >> v;
            vector <ll> path;
            unordered_map <ll , ll> mp;
            unordered_map <ll , ll> :: iterator itr;
            ll Lca = LCA(u , v);

			if(checktime[u][0] > checktime[v][0]) {
                swap(u, v);
            }
            if(u == v) {
                path.push_back(u);
            }
            else if(Lca == u || Lca == v) {
                // cout << "LCA" << endl;
                for(ll i = min(checktime[u][0] , checktime[v][0]) ; i <= max(checktime[u][0] , checktime[v][0]) ; i++) {
                    mp[timeStamp[i]] ++;
                }
                for(itr = mp.begin() ; itr != mp.end() ; itr++) {
                    if(itr -> second == 1) {
                        path.push_back(itr -> first);
                    }
                }
            }
            else{
                path.push_back(Lca);
                for(ll i = min(checktime[u][1] , checktime[v][1]); i <= max(checktime[u][0] , checktime[v][0]) ; i++) {
                    mp[timeStamp[i]] ++;
                }
                for(itr = mp.begin() ; itr != mp.end() ; itr++) {
                    if(itr -> second == 1) {
                        path.push_back(itr -> first);
                    }
                }
            }

            ll ans = calcAnswer(path);
            cout << ans % mod << endl;
        }

        for(ll i = 1 ; i <= n ; i++) {
            graph[i].clear();
            checktime[i].clear();
            factor[i].clear();
        }
    }
    return 0;
}
