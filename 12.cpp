#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc ll t; cin>>t; while(t--)
#define inn ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];
#define fora(i,n)for(ll i=0;i<n;i++)
#define forb(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define MOD 1000000007
#define F first
#define S second
#define pii pair<ll,ll>
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}
ll maxSubArraySum(vector<ll> a, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (ll i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{  /*
   ------------------------------------------------------------------
   |                                                                |
   |                                                                |
   |             AUTHOR: ANSHJAIN18                                 |
   |                                                                |
   |                                                                |
   ------------------------------------------------------------------ */
 tc
    {
     ll n;
     cin>>n;
     ll sum=0;
     ll arr[n];
     fora(i,n)
     {
         cin>>arr[i];
         sum+=arr[i];
     }
vector<ll> v1,v2;
     for(ll i=0;i<n-1;i++)
     {
         v1.push_back(arr[i]);
     }
for(ll i=1;i<n;i++)
    v2.push_back(arr[i]);
//cout<<maxSubArraySum(v1,(ll)v1.size())<<endl;
if(max(maxSubArraySum(v1,(ll)v1.size()),maxSubArraySum(v2,(ll)v2.size()))>=sum)
    cout<<"NO\n";
else cout<<"YES\n";


    };




return 0;


}
