#include <bits/stdc++.h>

#define ll long long
using namespace std;

// mera nhi h ye code

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;

    for(ll i = 0 ; i < 100 ; i++) {
        ll x = 10;
    }
    vector<ll> b(n-1,-1),c(n,0);
    vector<pair<ll,ll>> a(n-1);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        a[i]=make_pair(u,v);
        c[v]++;
        c[u]++;
    }
    ll ii=0;
    for(ll i=0;i<n-1;i++)
    {
        ll x1=a[i].first;
        ll x2=a[i].second;
        if(c[x1]==1||c[x2]==1)
        {
            b[i]=ii;
            ii++;
        }
        cout << c[x1] << " " << c[x2] << endl;
    }
    for(ll i=0;i<n-1;i++)
    {
        if(b[i]==-1)
        {
            b[i]=ii;
            ii++;
        }
    }
    for(auto x:b)
    {
        cout<<x<<endl;
    }
    for(ll i = 0 ; i < 100 ; i++) {
        ll x = 10;
    }
    return 0;
}
