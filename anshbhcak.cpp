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

/*

 /-----------------------------------------------------------/
 |                                                           |
 |                                                           |
 |                 AUTHOR: anshjain18                        |
 |                                                           |
 |                                                           |
 /------------------------------------------------------------/
*/
tc
    {

    ll n;
    cin>>n;
    ll arr[n];
    fora(i,n) cin>>arr[i];
    map<ll,vector<ll>> mp;
    fora(i,n)
        {

        mp[arr[i]].push_back(i);

        }
        ll flag=0;
    for(auto it:mp)
    {

        for(ll i=1;i<it.second.size();i++)
        {
            if(it.second[i]-it.second[i-1]>1)
            {
                flag=1;
                break;
            }
        }

    }
    if(flag)
        cout<<"YES\n";
    else cout<<"NO\n";




    };

return 0; }
