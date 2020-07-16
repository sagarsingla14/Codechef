//
// Created by Ansh Jain on 02-10-2019.
//
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n)for(ll i=0;i<n;i++)
#define forb(i,a,n) for(int i=a;i<n;i++)
int main()
{     tc {
        //THIS CODE IS CREATED BY ANSH_JAIN18
//        cout << "Enter the number of items\n";
        ll n,w,x,y;
        cin >> n>>w>>x>>y;
        ll ww[n],nn[n],wwc[n],nnc[n];
        ll ans=INT_MIN;
        pair<ll,ll> wu[n],nu[n];
        fora(i,n)
        {

            cin>>ww[i];

        }
        fora(i,n) {
            cin >> nn[i];
        }
//        sort(wu,wu+n);
copy(ww,ww+n,wwc);
        copy(nn,nn+n,nnc);
for(ll k=0;k<n;k++)
{

for(ll u=0;u<n;u++) {
    if(k==u)
        continue;
    else if(k<u)
    {
        nn[k]*=x;
        nn[u]*=y;

    } else
    {
        nn[k]*=y;
        nn[u]*=x;
    }


//        cout << "Enter the weights and profit of " << n << " items\n";
    pair<int, int> pw[n + 1];
    pw[0].first = 0;
    pw[0].second = 0;
    map<pair<int, int>, char> mp;
    char c = 'A';
    for (int i = 1; i <= n; ++i) {
//            cout << "ITEM " << c << endl;
//            cout << "Weight " << i << " Profit " << i << endl;
        pw[i].first = ww[i - 1];
        pw[i].second = nn[i-1];
        mp[{pw[i].first, pw[i].second}] = c;
        c++;
    }
    sort(pw, pw + n + 1);
//        cout << "The capacity of knapsack  is 15 \n";
    int knap[n + 1][w + 1];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < w + 1; ++j) {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (pw[i].first <= j)
                knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - pw[i].first] + pw[i].second);
            else knap[i][j] = knap[i - 1][j];

        }
    }

//        for(ll i=1;i<=n;i++)
//        {
//            for(ll j=0;j<=w;j++)
//            {
//                cout<<knap[i][j]<<" ";
//
//            }
//            cout<<"\n";
//        }
    int maxprof = knap[n][w];
    vector<ll> v;

    int j = w;

    for (int i = n; i > 0 && maxprof > 0; i--) {


        if (maxprof == knap[i - 1][j])
            continue;
        else {


            v.push_back(pw[i].second);

            maxprof = maxprof - pw[i].second;
            j = j - pw[i].first;
        }
    }

//        for(auto it:v)
//            cout<<it<<" ";
//        cout<<"\n";
//    sort(v.begin(), v.end());
//        sort(v1.begin(),v1.end());
//        if(v1.size()==1)
//        {
//            v1[v1.size()-1]*=max(x,y);
//        } else
//        {
//            v1[v1.size()-1]*=max(x,y);
//            v1[v1.size()-2]*=min(x,y);
//        }
ans=max(ans,accumulate(v.begin(),v.end(),0LL));
    copy(wwc,wwc+n,ww);
    copy(nnc,nnc+n,nn);
} }
//        cout<<max(accumulate(v.begin(),v.end(),0LL),accumulate(v1.begin(),v1.end(),0LL))<<"\n";
cout<<ans<<"\n";
    }

}
