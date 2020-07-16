#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector <ll> graph[100001];
vector <vector <pair <ll , ll> > > factor(100001);
ll visited[100001];
ll arr[100001];
bool isPrime[1000001];
vector <ll> path;
stack <ll> s;
ll pathFind , n , t;
ll ans;

void calcfactor() {
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

    for(ll i = 2 ; i * i <= 1000000 ; i++) {
        if(isPrime[i]) {
            for(ll j = i * i ; j <= 1000000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void returnPath() {
    // Checked
    while(!s.empty()) {
        path.push_back(s.top());
        s.pop();
    }
}

void dfs(ll u , ll v) {
    // Checked
    visited[u] = 1;
    s.push(u);
    if(u == v) {
        pathFind = 1;
        returnPath();
        return ;
    }
    for(auto i : graph[u]) {
        if(!visited[i]) {
            dfs(i , v);
        }
    }
    if(pathFind == 0 && !s.empty()) {
        s.pop();
    }
}

void findPath(ll u , ll v) {
    // Checked
    dfs(u , v);
}

int main() {

    memset(isPrime , true , sizeof(isPrime));
    sieve();
    isPrime[0] = false;
    isPrime[1] = false;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        for(ll i = 0 ; i < n - 1 ; i++) {
            ll a , b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset(arr , 0 , sizeof(arr));
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        calcfactor();

        ll q;
        cin >> q;
        while(q--) {
            ans = 1;
            pathFind = 0;
            ll u , v;
            cin >> u >> v;

            path.clear();
            memset(visited , 0 , sizeof(visited));
            findPath(u , v);

            unordered_map <ll , ll> mp;
            for(ll i = 0 ; i < path.size() ; i++) {
                ll vertex = path[i];
                for(ll j = 0 ; j < factor[vertex].size() ; j++) {
                    ll primeNum = factor[vertex][j].first;
                    ll primeNumPower = factor[vertex][j].second;
                    mp[primeNum] += primeNumPower;
                }
            }

            // for(auto itr : mp) {
            //     cout << itr.first << " " << itr.second << endl;
            // }
            //
            // cout << "Path -> ";
            // for(ll i = 0 ; i < path.size() ; i++) {
            //     cout << path[i] << " " ;
            // }
            // cout << endl;

            for(auto itr : mp) {
                ll divisors = (itr.second + 1);
                ans *= divisors;
                ans %= mod;
            }
            pathFind = 0;

            cout << ans % mod << endl;

            memset(visited , 0 , sizeof(visited));
            path.clear();
            while(!s.empty()) {
                s.pop();
            }
            ans = 0;
        }
        memset(arr , 0 , sizeof(arr));
        for(ll i = 0 ; i <= n ; i++) {
            graph[i].clear();
            factor[i].clear();
        }
    }
    return 0;
}
