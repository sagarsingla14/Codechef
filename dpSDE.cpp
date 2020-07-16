#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007
ll n,W,x,y;
ll dp[1001][1001][2][2];

ll knapsack(auto& v,auto& w,int i,int Z,int a,int b)
{

    if(i==n||(!Z)) return 0;

    if(dp[i][Z][a][b]!=-1) return dp[i][Z][a][b];

    ll ans=0;
    if(w[i]<=Z) ans=max(ans,v[i]+knapsack(v,w,i+1,Z-w[i],a,b));
    ans=max(ans,knapsack(v,w,i+1,Z,a,b));
    if(w[i]<=Z)
    {
        if(a) ans=max(ans,v[i]*x+knapsack(v,w,i+1,Z-w[i],0,b));
        if(b) ans=max(ans,v[i]*y+knapsack(v,w,i+1,Z-w[i],a,0));
    }
    dp[i][Z][a][b]=ans;
    return ans;
}

int main() {

for(int i = 0 ; i < 10 ; i++) {
    int x = 10;
}
    tc
    {
        cin>>n>>W>>x>>y;
        memset(dp,-1,sizeof(dp));
        vector<ll> weight(n),profit(n);
        fora(i,n) cin>>weight[i];
        fora(i,n) cin>>profit[i];

        cout<<knapsack(profit,weight,0,W,1,1)<<"\n";
    }

    for(int i = 0 ; i < 10 ; i++) {
        int x = 10;
    }


return 0; }
