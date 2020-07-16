#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector <vector <pair <ll , ll> > > factor(100001);
bool isPrime[1000001];
ll n;
ll mp[1000001];

void calcfactor(ll arr[]) {
    // Checked
    for(ll i = 1 ; i <= n ; i++) {
        ll term = arr[i];
        for(ll j = 2 ; j <= sqrt(arr[i]) ; j++) {
            if(isPrime[j]) {
                ll cnt = 0;
                while(term % j == 0) {
                    term /= j;
                    cnt ++;
                }
                if(cnt) {
                    factor[i].push_back(make_pair(j , cnt));
                }
            }
        }
        if(term > 1) {
            factor[i].push_back(make_pair(term , 1));
        }
    }
}

void sieve() {
    // Checked
    for(ll i = 2 ; i * i <= 1000000 ; i++) {
        if(isPrime[i]) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void dfs(ll current , ll d , ll p , ll *depth , ll *parent , vector <ll> graph[]) {
    parent[current] = p;
    depth[current] = d;
    for(auto child : graph[current]) {
        if(child != p) {
            dfs(child , d + 1 , current , depth , parent , graph);
        }
    }
}


vector <ll> getpath(ll a , ll b , ll depth[] , ll parent[]) {
    vector <ll> path1;
    vector <ll> path2;
    path1.push_back(a);
    path2.push_back(b);
    while(a != b) {
        if(depth[a] > depth[b]) {
            a = parent[a];
            path1.push_back(a);
        }
        else if(depth[a] < depth[b]) {
            b = parent[b];
            path2.push_back(b);
        }
        else if(depth[a] == depth[b]) {
            a = parent[a];
            b = parent[b];
            path1.push_back(a);
            path2.push_back(b);
        }
    }

    reverse(path2.begin(), path2.end());
    path2.erase(path2.begin());
    path1.insert(path1.end(), path2.begin(), path2.end());

    return path1;
}

int main() {

    memset(isPrime , true , sizeof(isPrime));
    memset(mp , 0 , sizeof(mp));
    sieve();
    isPrime[0] = false;
    isPrime[1] = false;

    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector <ll> graph[n + 1];
        for(ll i = 0 ; i < n - 1 ; i++) {
            ll a , b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        ll arr[n + 1];
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        calcfactor(arr);

        ll depth[n + 1] = {0};
        ll parent[n + 1] = {0};
        dfs(1 , 0 , -1 , depth , parent , graph);

        ll q;
        cin >> q;
        while(q--) {
            ll u , v;
            cin >> u >> v;
            vector <ll> path;
            path = getpath(u , v , depth , parent);
            unordered_set <ll> s;
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
            cout << ans % mod << endl;
        }

        for(ll i = 1 ; i <= n ; i++) {
            graph[i].clear();
            factor[i].clear();
        }
    }
    return 0;
}
