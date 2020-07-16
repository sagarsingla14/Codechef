#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007
#define endl "\n"
#define F first
#define S second
#define vi vector<ll>
#define pii pair<ll,ll>
int main()
{

    fastio
    ll t;
    cin >> t;
    while(t--){

    ll n,k;
    cin>>n>>k;
    ll arr[n];
    map<ll,ll> mp;
    fora(i,n) cin>>arr[i];
    pair<ll,ll> use[n/2];
    for(ll i=0;i<n/2;i++) {

        ll a=arr[i];
        ll b=arr[n-1-i];
        mp[a+b]++;
        if(a>b) {
            swap(a,b);
        }
        ll a1=b+1;
        ll a2=b+k;
        ll b2=a+k;
        ll b1=a+1;
        ll x=min({a1,a2,b1,b2});
        ll y=max({a1,a2,b1,b2});
        use[i]={x,y};
    }
ll cnt=INT_MAX;
    ll freq[(ll)(4e5)+1]={0};
        int minn = INT_MAX;
        int maxx = INT_MIN;
        int li, ri;
        for (int i = 0; i < n/2; i++)
        {
            li = use[i].first;
            freq[li] = freq[li] + 1;
            ri = use[i].second;
            freq[ri + 1] = freq[ri + 1] - 1;

            if (li < minn)
                minn = li;
            if (ri > maxx)
                maxx = ri;
        }

        // Constructing the frequency array
        ll nn=INT_MAX;
        ll mm=INT_MIN;
        for(auto it:mp)
        {
            nn=min(nn,it.first);
            mm=max(mm,it.first);
        }
        for (int i = minn; i <= maxx; i++)
            freq[i] = freq[i] + freq[i - 1];
        for(ll i=nn;i<=mm;i++) {
            if(freq[i]>=n/2)
            {

                cnt=min(cnt,(n/2)-mp[i]);
            }


else cnt=min(cnt,freq[i]-mp[i]+2*((n/2)-freq[i]));
    }

cout<<cnt<<"\n";

}

return 0;
}
