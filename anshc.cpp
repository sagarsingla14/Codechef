#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007
#define endl "\n"
#define F first
#define S second
#define vi vector<ll>
#define pii pair<ll,ll>
//pair<pair<ll,ll>,ll> def[(ll)2e5];
ll depth[(ll)2e5];
ll subtr[(ll)2e5];
ll net[(ll)2e5];
set<ll> indus;
void dfs(ll node, ll parent, vector<ll> arr[])
{
    if(parent==-1)
        depth[node]=0;
    else
depth[node]=depth[parent]+1;
    subtr[node]=1;
    for(auto it:arr[node])
    {
        if(it!=parent)
            dfs(it,node,arr);
    }
subtr[parent]+=subtr[node];

}
void mydfs(ll node,ll parent,vector<ll> arr[])
{
    if(parent==-1)
    {
        if(indus.find(node)!=indus.end())
            net[node]=0;
        else net[node]=1;

    } else
    {
        if(indus.find(node)!=indus.end())
        {
            net[node]=net[parent];

        }
        else net[node]=net[parent]+1;
    }
    for(auto it:arr[node])
        if(it!=parent)
            mydfs(it,node,arr);

}
bool comp(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b)
{

    if(a.first.first!=b.first.first)
        return a.first.first>b.first.first;

    else if(a.first.first==b.first.first) return a.first.second<b.first.second;

}

int main()
{

ll n,k;
cin>>n>>k;
vector<ll> arr[n];
fora(i,n-1)
    {
    ll u,v;
    cin>>u>>v;
    u--;
    v--;
    arr[u].push_back(v);
    arr[v].push_back(u);
    }
    dfs(0,-1,arr);
pair<pair<ll,ll>,ll> def[n];
fora(i,n)
    {
   def[i].first.first=depth[i];
   def[i].first.second=subtr[i];
   def[i].second=i;
    }

    sort(def,def+n,comp);
ll ans=0;
map<ll,ll> mp,mp1;
vector<ll> v;
for(ll i=0;i<k;i++)
{
   // cout<<def[i].first.first<<" "<<def[i].first.second<<" "<<def[i].second<<"\n";
    mp[def[i].first.first]++;
    indus.insert(def[i].second);

}

mydfs(0,-1,arr);
//fora(i,n)
//cout<<net[i]<<" ";
//cout<<"\n";
for(ll i=0;i<k;i++)
    ans+=net[def[i].second];
//for(auto it:mp)
//    v.push_back(it.first);
//sort(v.begin(),v.end(),greater<ll>());
//for(auto it:v)
//    cout<<it<<" ";
//cout<<"\n";
//fora(i,n)
//mp1[depth[i]]++;
//
//for(auto it:v)
//{
//    ll cnt=min(k,mp[it]);
//    ll x=mp[it-1];
//    ll y=mp1[it-1];
//    if(cnt<=y-x)
//    ans+=(cnt*it);
//    else
//    {
//        ll left=cnt-(y-x);
//        ans+=(y-x)*it;
//        ans+=left*(it-1);
//    }
//}
cout<<ans<<"\n";
return 0; }
