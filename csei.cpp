#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

bool isPrime(ll n)
{

    if (n <= 1)  return false;
    if (n <= 3)  return true;


    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}
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
    inn;
ll cnt=0;
for(ll i=0;i<n;i++)
{
    for(ll j=i+1;j<n;j++)
    {
        ll x=arr[i]+arr[j];
        if(isPrime(x))
            cnt++;
    }
}
cout<<cnt<<"\n";

    };

return 0; }
