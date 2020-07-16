#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int MAXN = 40005;
const int MAXM = 100005;
#define ll int
const int LN = 19;


ll isPrime[1000001];
vector <vector <pair <ll , ll> > > factor(100001);
int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN];
vector <map <ll ,ll> > ANS(MAXM);
int d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];

struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];

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


void calcfactor() {
	// Checked
	for(ll i = 1 ; i <= N ; i++) {
		unordered_map <ll , ll> m;
		ll term = A[i];
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

// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur;
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}

// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

inline void check(int x, map <ll , ll> &res){
	// If (x) occurs twice, then don't consider it's value
	if ( (VIS[x]) and (--VAL[A[x]] == 0) ) {
		res[x] --;
	}
	else if ( (!VIS[x]) and (VAL[A[x]]++ == 0) ) {
		res[x] ++;
	}
	VIS[x] ^= 1;
}



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


void compute(){

	// Perform standard Mo's Algorithm
	int curL = Q[0].l, curR = Q[0].l - 1;
	map <ll , ll> res;

	for (int i = 0; i < M; i++){

		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);

		int u = ID[curL], v = ID[curR];

		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);

		ANS[Q[i].id] = res;

		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		res.clear();
	}

	for(int i = 0; i < M; i++) {
		map <ll , ll> nodes = ANS[i];
		vector <ll> path;
		for(auto i : nodes) {
			if(i.second != 0)
				path.push_back(i.first);
		}
		ll finalanswer = calcAnswer(path);
		cout << finalanswer % mod << endl;
	}

	// printf("%d\n", ANS[i]);
}




int main(){

	memset(isPrime , 0 , sizeof(isPrime));
	sieve();

	int u, v, x;

	//
	// while (scanf("%d != EOF){
		cin >> N;
		// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (int i = 1; i <= N; i++) adjList[i].clear();

		// Inputting Values

		// Inputting Tree
		for (int i = 1; i < N; i++){
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
		memcpy(d + 1, A + 1, sizeof(int) * N);

		calcfactor();

		// Compressing Coordinates
		sort(d + 1, d + N + 1);
		K = unique(d + 1, d + N + 1) - d - 1;
		for (int i = 1; i <= N; i++) A[i] = lower_bound(d + 1, d + K + 1, A[i]) - d;

		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int size = sqrt(cur);

		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;
		cin >> M;
		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}

		sort(Q, Q + M);
		compute();
	}
