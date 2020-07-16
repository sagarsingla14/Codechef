#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n)for(ll i=0;i<n;i++)
#define forb(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define MOD 1000000007
#define F first
#define S second
#define pii pair<ll,ll>
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}

int main()
{
 //THIS CODE IS CREATED BY ANSHJAIN18
 fastio
 tc
    {
     ll n,m;
     cin>>n>>m;
     ll mat[n][m];
     fora(i,n)
     fora(j,m)
     cin>>mat[i][j];
     ll ans=0;
     for(ll i=0;i<n;i++)
     {
         for(ll j=0;j<m;j++)
         {
             ll horz=0,vert=0;

             ll a=i-1,b=i+1,c=j-1,d=j+1;
             while(a>=0&&b<n&&c>=0&&d<m)
             {
                 if(mat[a][j]==mat[b][j]&&mat[i][c]==mat[i][d])
                 {
                     ans++;
                     a--;
                     b++;
                     c--;
                     d++;

                 }
                 else break;

             }

             ans++;

         }

     }
     cout<<ans<<endl;

    };




return 0;


}
