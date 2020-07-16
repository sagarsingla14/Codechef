#include<bits/stdc++.h>
using namespace std;
#define ll int


// struct Compare {
    bool Compare(pair<int, int> &a,
                              pair<int, int> &b)
    { return a.first > b.first && a.second<b.second; }
    // };

int main()
{

    map<int, int, Compare> mymap;
    // priority_queue<pair<int,int>,
    //                vector<pair<int,int> >,
    //                Compare> Q;
    // int n;
    // cin>>n;
    //
    // for(int i=0;i<n;i++)
    // {
    //     ll a,b;
    //     cin>>a>>b;
    //     Q.push(make_pair(a,b));
    // }
    //
    // for(ll i=0;i<n;i++)
    // {
    //     pair<ll,ll> m;
    //     m=Q.top();
    //     cout<<m.first<<" "<<m.second<<"\n";
    //     Q.pop();
    // }
}
