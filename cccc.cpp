#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap unordered_map
#define pb push_back
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(auto& i:v) cin>>i;

        vector<ll> p;
        ll l=v[0],m=0,ans=0;
        for(int i=1;i<n;i++)
        {
            if(v[i]<l) m=max(m,l-v[i]);
            else l=v[i];

            ll s=0;  // seconds for i-th number
            while((1LL<<s)<=m) s++;
            ans=max(s,ans);  // max till  i-th
        }

        cout<<ans<<"\n";
    }

    return 0;
}
