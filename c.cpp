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
    ll n,k;
    cin>>n>>k;
    if(n<k*k)
    {
        cout<<"NO\n";
        continue;
    }
    if(k%2!=0)
    {

        if(n&1)
        {

            cout<<"YES\n";
        }
        else cout<<"NO\n";

    } else
    {
        if(n%2==0)
        {
            cout<<"YES\n";

        }
        else cout<<"NO\n";

    }


    };
return 0; }
