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
tc
    {
    ll n;
    cin>>n;
    for(ll i = 0 ; i < n ; i++) {
        ll x= 0;
    }
    string s;
    cin>>s;
    pair<ll,ll> start={0,0};
    map<pair<ll,ll>,vector<ll>> mp;
    mp[{0,0}].push_back(0);
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='L')
        {
            start.first--;
            mp[start].push_back(i+1);
        }
        else if(s[i]=='R')
        {
            start.first++;
            mp[start].push_back(i+1);
        }
        else if(s[i]=='U')
        {
            start.second++;
            mp[start].push_back(i+1);
        } else
        {
            start.second--;
            mp[start].push_back(i+1);
        }
    }
//    for(auto it:mp)
//    {
//        cout<<it.first.first<<" "<<it.first.second<<"\n";
//    }
    ll l=0,r=0;
    ll ansd=INT_MAX;
    ll flag=0;
    for(auto it:mp)
    {
        if(mp[it.first].size()==1)
            continue;
        else
        {  flag=1;
            for(ll i=1;i<mp[it.first].size();i++)
            {
                if(mp[it.first][i]-mp[it.first][i-1]<ansd)
                {
                    ansd=mp[it.first][i]-mp[it.first][i-1];
                    l=mp[it.first][i-1]+1;
                    r=mp[it.first][i];
                }

            }

        }



    }
if(!flag)
    cout<<-1<<"\n";
else
{
    cout<<l<<" "<<r<<"\n";
}



    };



return 0; }
