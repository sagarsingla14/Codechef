#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(int i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007
map<ll,ll> pr;
set<ll> prime(ll n)
{   set<ll> s;
    pr[1]=1;
    while (n % 2 == 0) {
        {
            pr[2]++;
            n /= 2;
        }

    }
    for (ll i = 3; i * i <= n; i += 2) {

        if (n % i == 0) {
            pr[i]++;
            n/=i;

            while (n % i == 0)
            {   pr[i]++;
                n /= i;
            }

        }


    }
    if(n>1)
        pr[n]++;
    ll flag=0;
    for(auto it:pr)
        if(it.second&1){flag=1;
            s.insert(it.first); }
    if(!flag)
        s.insert(-1);

    pr.clear();
    return s;
}
int32_t main()
{
    tc
    {
        ll n,m;
        cin>>n>>m;
//        set<ll> ss=prime(n);

        vector<ll> xn,xp,yn,yp;
        ll al=0,bl=0;
        map<ll,ll> sqx,sqy;
        fora(i,n)
        {
            ll x;
            cin>>x;
//            if(x==0)
//                al=1;
            if(x>=0) {
                if(x==0)
                    al=1;
                else
                    xp.push_back(x); }
            else xn.push_back(abs(x));
            sqx[x*x]++;
        }
        fora(i,m)
        {
            ll y;
            cin>>y;

            if(y>=0){
                if(y==0)
                    bl=1;
                else
                yp.push_back(y); }
            else yn.push_back(abs(y));
            sqy[y*y]++;
        }
        map <ll , ll> :: iterator itr;

        for(itr = sqx.begin() ; itr != sqx.end() ; itr++) {
            cout << itr -> first << " " << itr -> second << endl;
        }
        cout << endl;
        for(itr = sqy.begin() ; itr != sqy.end() ; itr++) {
            cout << itr -> first << " " << itr -> second << endl;
        }
//        sort(xp.begin(),xp.end());
//        sort(yp.begin(),yp.end());
        ll cnt=0;
        if(al)
            cnt+=(n-1)*m;
        if(bl)
            cnt+=(m-1)*n;
map<set<ll>,vector<ll>> parxn,parxp,paryn,paryp;
for(ll i=0;i<xp.size();i++)
{
    set<ll> s=prime(xp[i]);
    parxp[s].push_back(i);

}

for(ll i=0;i<xn.size();i++)
{

    set<ll> s=prime(xn[i]);
    if(parxp.find(s)!=parxp.end())
    {

        for(auto it:parxp[s])
        {
            ll ans=xn[i]*xp[it];
            if(sqy.find(ans)!=sqy.end())
            {
                cnt+=sqy[ans];
            }

        }

    }

}
for(ll i=0;i<yp.size();i++)
{
    set<ll> s=prime(yp[i]);
    paryp[s].push_back(i);
}
for(ll i=0;i<yn.size();i++)
{
set<ll> s=prime(yn[i]);
if(paryp.find(s)!=paryp.end())
{
for(auto it:paryp[s])
{
    ll ans=yn[i]*yp[it];
    if(sqx.find(ans)!=sqx.end())
        cnt+=sqx[ans];

}

}
}

        cout<<cnt<<"\n";

    };



    return 0; }
