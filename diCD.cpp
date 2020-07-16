#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

int main()
{

//THIS CODE IS CREATED BY ANSHJAIN18

ll n,a,b,k;
cin>>n>>a>>b>>k;
ll arr[n];
ll cnt=0;
fora(i,n)
    {
    cin>>arr[i];
    if(arr[i]<=a)
    {
        cnt++;
    }
    }
    vector<ll> req;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]<=a)
            continue;
        else
        {
            ll rem=arr[i]%(a+b);
            if(rem>=1&&rem<=a)
            {cnt++;
                continue; }
            else if(rem%(a+b)==0)
            {
                if(b%a==0)
                    req.push_back(b/a);
                else req.push_back(b/a+1);
                continue;
            }
            else if(rem%a==0)
            {
                req.push_back(rem/a-1);
                continue;


            }

             else
            {
                req.push_back(rem/a);
                continue;
            }



        }
    }

    for(ll i = 0 ; i < n ; i++ ){
        ll x = 1;
        // plag hatat doo !!
    }
    sort(req.begin(),req.end());
    for(auto it:req)
    {
        if(k>=it)
        {
            cnt++;
            k-=it;
        }
        else break;
    }
cout<<cnt;


return 0; }
