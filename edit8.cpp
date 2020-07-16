#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

void cal_height(ll node, ll i,unordered_map<ll, vector<ll> > &tree,ll *heights, ll *v1, ll &max_height){
	heights[node]=i;
	v1[node]=1;
	max_height = max(max_height,i);
	if (tree.find(node)!=tree.end()){
		for(auto nnode: tree[node]){
			if(!v1[nnode]){
				cal_height(nnode, i+1, tree, heights, v1, max_height);
			}
		}
	}
}

void update_seg(ll *leaf_seg, ll leaf_seg_size, ll p, ll value){
	for( p+=leaf_seg_size; p>0; p>>=1 ){
		leaf_seg[p]+=value;
	}
}

ll query_seg(ll *leaf_seg, ll leaf_seg_size, ll r){
	ll res=0, l=leaf_seg_size;
	for(r+=leaf_seg_size+1;l<r;l>>=1,r>>=1){
		if(l&1) res += leaf_seg[l++];
		if(r&1) res += leaf_seg[--r];
	}
	return res;
}

void dfs(ll *leaf_seg, ll leaf_seg_size, unordered_map<ll, vector<ll> > &tree, unordered_map<ll, vector<ll> > &queries, unordered_map<ll, vector<pair<ll,ll> > > &updates, unordered_map<ll, ll> &ans,ll *heights, ll *v1, ll max_height, ll node, unordered_map<ll, ll> &sums){
	ll value, index;
	v1[node]=1;

	vector<ll> childs;
	if(tree.find(node)!=tree.end()){
		for(auto nnode: tree[node]){
			if(!v1[nnode]){
				childs.push_back(nnode);
			}
		}
	}

	bool is_leaf = childs.size()<=0;

	if(updates.find(node)!=updates.end()){
		for(auto p: updates[node]){
			sums[p.first]+=p.second;
			update_seg(leaf_seg,leaf_seg_size, p.first+max_height+1,p.second);
		}
	}

	if(queries.find(node)!=queries.end()){
		for(auto index: queries[node]){
			if(is_leaf){
				ans[index] = query_seg(leaf_seg, leaf_seg_size,index+max_height-heights[node]+1);
			}else{
				if(sums.find(index-heights[node])!=sums.end()){
					ans[index] = sums[index-heights[node]];
				}
				else{
					ans[index]=0;
				}
			}
		}
	}

	for(auto child: childs){
		if(!v1[child]){
			dfs(leaf_seg, leaf_seg_size, tree, queries, updates, ans, heights, v1, max_height, child, sums);
		}
	}

	if(updates.find(node)!=updates.end()){
		for(auto p: updates[node]){
			sums[p.first] -= p.second;
			update_seg(leaf_seg,leaf_seg_size, p.first+max_height+1,-p.second);
		}
	}

}



int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll i, value, node, n,q;
	cin>>n; cin>>q;
	unordered_map<ll, ll> ans, sums;
	unordered_map<ll, vector<ll> > tree, queries;
	unordered_map<ll, vector<pair<ll,ll> > > updates;
	vector<ll> ans_indexes;

	for(i=0;i<n-1;i++){
		ll x,y; cin>>x; cin>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	ll heights[n+1], v1[n+1];
	memset(heights, 0, (n+1)*sizeof(heights[0]));
	memset(v1, 0, (n+1)*sizeof(v1[0]));
	ll max_height = 0;

	cal_height(1, 0, tree, heights, v1, max_height);
	cout << endl << "-------------------HEIGHTS---------------------" << endl;

	for(ll i = 0; i <= n ; i++) {
		cout << heights[i] << " ";
	}
	cout << endl;
	cout << endl << "-------------------V1---------------------" << endl;

	for(ll i = 0; i <= n ; i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	for(i=1; i<=n; i++){
		cin>>value;
		if(value) updates[i].push_back( make_pair( -1-heights[i], value));
	}

	for(i=0;i<q;i++){
		char symbol; cin>>symbol;
		if(symbol=='+'){
			cin>>node; cin>>value;
			updates[node].push_back(make_pair( i-heights[node], value));
		}
		else{
			cin>>node;
			ans_indexes.push_back(i);
			queries[node].push_back(i);
		}
	}
	cout << endl << "-------------------UPDATES---------------------" << endl;

	for(i=1; i<=n; i++){
		for(ll j = 0; j < updates[i].size() ; j++) {
			cout << "( " << updates[i][j].first << " - " << updates[i][j].second << " ) ,   ";
		}
		cout << endl;
	}
	cout << endl;

	cout << endl << "-------------------ANS_INDEXES---------------------" << endl;


	for(ll i = 0 ; i < ans_indexes.size() ; i++ ){
		cout << ans_indexes[i] << " ";
	}
	cout << endl;
	cout << endl << "-------------------QUEIRES---------------------" << endl;
	for(ll i = 0 ; i <= n ; i++ ){
		for(ll j = 0; j < queries[i].size() ; j++) {
			cout << queries[i][j] << " ";
		}
		cout << endl;
	}
	cout << "maxHeight -> " << max_height << endl;
	return 0;


	ll leaf_seg_size = max_height+1+q;
	ll leaf_seg[2*leaf_seg_size];
	memset(leaf_seg, 0, (2*leaf_seg_size)*sizeof(leaf_seg[0]));
	memset(v1, 0, (n+1)*sizeof(v1[0]));
	dfs(leaf_seg, leaf_seg_size, tree, queries, updates, ans, heights, v1, max_height, 1, sums);

	for(auto key: ans_indexes){
		cout<<ans[key]<<endl;
	}

	return 0;
}
