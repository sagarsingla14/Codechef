// Sparse Matrix DP approach to find LCA of two nodes
// LCA taken from geeksforgeeks
// https://www.geeksforgeeks.org/lca-for-general-or-n-ary-trees-sparse-matrix-dp-approach-onlogn-ologn/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100009
#define level 18

#define ll long long
#define MOD 1000000007
#define ssize 1000009

class v_p_p{
public:
    int sstart;
    int send;
    int i;
    int lca;
    v_p_p(int s,int e,int ind,int lca1){
        sstart = s;
        send = e;
        i = ind;
        lca = lca1;
    }

};


vector<unordered_map<int,int> > vmactual(MAXN);


vector<int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=0; i<tree[cur].size(); i++)
	{
		if (tree[cur][i] != prev)
			dfs(tree[cur][i], cur);
	}
}


void dfs3(int cur, int prev,vector<int>& flatarr)
{

    flatarr.push_back(cur);
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=0; i<tree[cur].size(); i++)
	{
		if (tree[cur][i] != prev)
			dfs3(tree[cur][i], cur,flatarr);
	}
    flatarr.push_back(cur);
}


// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n)
{
	for (int i=1; i<level; i++)
	{
		for (int node = 1; node <= n; node++)
		{
			if (parent[node][i-1] != -1)
				parent[node][i] = parent[parent[node][i-1]][i-1];
		}
	}
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u, int v)
{
	if (depth[v] < depth[u])
		swap(u, v);

	int diff = depth[v] - depth[u];

	// Step 1 of the pseudocode
	for (int i=0; i<level; i++)
		if ((diff>>i)&1)
			v = parent[v][i];

	// now depth[u] == depth[v]
	if (u == v)
		return u;

	// Step 2 of the pseudocode
	for (int i=level-1; i>=0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}

void addEdge(int u,int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}


vector<int> seive(ssize,1);
void seives(){
    for(ll i = 2 ; i * i <= ssize ; i++) {
        if(seive[i] == 1) {
            seive[i] = i;
            for(ll j = i * i ; j <= ssize ; j += i) {
                seive[j] = i;
            }
        }
    }

    for(ll i = 2 ; i < ssize ; i++) {
        if(seive[i] == 1) {
            seive[i] = i;
        }
    }
}

int bsize = 0;
bool comp(v_p_p a,v_p_p b){
    if(a.sstart/bsize != b.sstart/bsize){
       return a.sstart/bsize < b.sstart/bsize;
    }
    else{
        return a.send < b.send;
    }
    return false;
}



void sforward(int index,unordered_map<int,int> & mmp,unordered_map<int,int> &sol){
    if(mmp[index] == 1){
        for (auto j:vmactual[index])
        {
            sol[j.first] -= j.second;
        }
    mmp[index]--;
    }
    if(mmp[index] == 2){
        for (auto j:vmactual[index])
        {
            sol[j.first] += j.second;
        }
    mmp[index]--;
    }
}


void sbackward(int index,unordered_map<int,int> & mmp,unordered_map<int,int> &sol){
    if(mmp[index] == 1){
        for (auto j:vmactual[index])
        {
            sol[j.first] -= j.second;
        }
        mmp[index]++;
    }
    if(mmp[index] == 0){
        for (auto j:vmactual[index])
        {
            sol[j.first] += j.second;
        }
        mmp[index]++;
    }
}


void ebackward(int index,unordered_map<int,int> & mmp,unordered_map<int,int> &sol){
    if(mmp[index] == 1){
        for (auto j:vmactual[index])
        {
            sol[j.first] -= j.second;
        }
    mmp[index]--;
    }
    if(mmp[index] == 2){
        for (auto j:vmactual[index])
        {
            sol[j.first] += j.second;
        }
    mmp[index]--;
    }
}


void eforward(int index,unordered_map<int,int> & mmp,unordered_map<int,int> &sol){
    if(mmp[index] == 1){
        for (auto j:vmactual[index])
        {
            sol[j.first] -= j.second;
        }
    mmp[index]++;
    }
    if(mmp[index] == 0){
        for (auto j:vmactual[index])
        {
            sol[j.first] += j.second;
        }
    mmp[index]++;
    }
}


// driver function
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seives();
	int t;
    cin>>t;
    while(t--){
        memset(parent,-1,sizeof(parent));
        memset(depth,0,sizeof(depth));
        for(int i=0;i<MAXN;i++){
            tree[i].clear();
        }
        vmactual.clear();
        int n;
        cin>>n;
        for (int i = 0; i < n-1; i++)
        {
            int x,y;
            cin>>x>>y;
            addEdge(x,y);
        }

        vector<int> flattenarray;
        dfs3(1,0,flattenarray);
	    precomputeSparseMatrix(n+1);

        for(int i=1;i<=n;i++){
            int value;
            cin>>value;
            unordered_map<int,int>  msat;
            while(value != 1){
                if(msat.find(seive[value])==msat.end())
                    msat[seive[value]] = 1;
                else
                    msat[seive[value]]++;
                value = value/seive[value];
            }
            vmactual[i] =  msat;
        }

        map<pair<int,int>,int> m_flatarr;
        for (int i = 0; i < flattenarray.size(); i++)
        {
            if(m_flatarr.find(make_pair(flattenarray[i],0)) == m_flatarr.end()){
                m_flatarr[make_pair(flattenarray[i],0)] = i;
            }
            else{
                m_flatarr[make_pair(flattenarray[i],1)] = i;
            }
        }


        int q;
        cin>>q;
        vector<v_p_p> vpp;
        bsize = int(sqrt(n));
        for(int i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            int LCA = lca(u,v);
            unordered_map<int,int> sol;
            int sindex,send;

            if(depth[u] > depth[v]){
                swap(u,v);
            }

            if(LCA == u){
                sindex = min(m_flatarr[make_pair(u,0)],m_flatarr[make_pair(v,0)]);
                send = max(m_flatarr[make_pair(u,0)],m_flatarr[make_pair(v,0)]);
                LCA = -1;
            }

            else{
                sindex = min(m_flatarr[make_pair(u,1)],m_flatarr[make_pair(v,1)]);
                send = max(m_flatarr[make_pair(u,0)],m_flatarr[make_pair(v,0)]);
                sol = vmactual[LCA];
            }

            v_p_p cppp(sindex,send,i,LCA);
            vpp.push_back(cppp);

        }

        sort(vpp.begin(),vpp.end(),comp);

        vector<long long> ans(q,1);
        unordered_map<int,int> mmp;
        unordered_map<int,int> sol;
        int currstart = vpp[0].sstart;
        int currend = vpp[0].send;


        for (int i = currstart; i <= currend; i++)
        {
            eforward(flattenarray[i],mmp,sol);
        }
        if(1){
            unordered_map<int,int> sol1 = sol;
            if(vpp[0].lca != -1){
                for (auto a: vmactual[vpp[0].lca])
                {
                    sol1[a.first] += a.second;
                }
            }
            for (auto k:sol1)
            {
                if(k.second>0){
                    ans[vpp[0].i]  = (ans[vpp[0].i]*(k.second+1))%MOD;
                }
            }
        }


        for (int j = 1; j < vpp.size(); j++)
        {
            if(currstart != vpp[j].sstart){
                while(currstart < vpp[j].sstart){
                    sforward(flattenarray[currstart],mmp,sol);
                    currstart++;
                }
                while (currstart > vpp[j].sstart)
                {
                    currstart--;
                    sbackward(flattenarray[currstart],mmp,sol);

                }
            }

            if(currstart>=currend){
                sol.clear();
                sol = vmactual[flattenarray[currstart]];
                currend = currstart;
                mmp.clear();
                mmp[flattenarray[currstart]] += 1;
            }

            if(currend != vpp[j].send){
                while(currend < vpp[j].send){
                    currend++;
                    eforward(flattenarray[currend],mmp,sol);
                }
                while (currend > vpp[j].send)
                {
                    ebackward(flattenarray[currend],mmp,sol);
                    currend--;
                }
            }

            unordered_map<int,int> sol1 = sol;

            if(vpp[j].lca != -1 ){
                for (auto a: vmactual[vpp[j].lca])
                {
                    sol1[a.first] += a.second;
                }
            }

            for (auto k:sol1)
                if(k.second>0){
                {
                    ans[vpp[j].i]  = (ans[vpp[j].i]*(k.second+1))%MOD;
                }
            }
        }

        for (int i = 0; i < q; i++)
        {
           cout<<ans[i]<<endl;
        }
    }
	return 0;
}
