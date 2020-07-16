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
int main()
{
fastio
tc {

    int n,k;
    cin>>n>>k;
    int reqset=k/(n-1)+(k%(n-1)!=0);
    int lborder=n*(reqset-1);
    cout<<lborder+k-((n-1)*(reqset-1))<<"\n";



};


return 0; }
