#include <bits/stdc++.h>
#include<utility>
#include<map>
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
ll pow1(ll n,ll p)
{
	if(p==0)	return 1;
	ll x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}

using  namespace std;

int main()
{
    ll t;
    std::cin >> t;
    while(t--)
    {
        ll n;
        std::cin >> n;
        ll a[n],i,j=0,b[n]={0},c[n]={0},d[n]={0},sum=0,sum2=0;
        for(i=0;i<n;i++)
        {
            std::cin >> a[i];
        }
        ll k=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                d[k]++;
                sum2++;
            }
            else
            {
                k++;
            }
        }
        sort(a,a+n);
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                b[j]++;
                sum++;
            }
            else
            {
                j++;
            }
        }
        sort(b,b+j);
        if(b[j-1]+1==3)
        {
            std::cout << "YES" << "\n";
            continue;
        }
        if(b[j-1]==0)
        {
            std::cout << "NO" << "\n";
            continue;
        }
        if(sum2==sum)
        std::cout << "NO" << "\n";
        else
        std::cout << "YES" << "\n";
    }

}
