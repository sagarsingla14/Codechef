#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

int main() {
    for(ll i = 0; i <= 10 ; i++){
        ll x =1;
    }
    tc
    {
        ll n,m;
        cin>>n>>m;
        for(ll i = 0 ; i < 10 ; i++) {
            ll x = 1;
        }
        pair<ll,ll> arr[n];
        fora(i,n)
        {

            cin>>arr[i].first;
            arr[i].second=i;


        }
        sort(arr,arr+n);
        ll flag=0;


        set<ll> pos;

        fora(i,m) {
            ll ele;
            cin>>ele;
            pos.insert(ele-1);
        }

        if(n==1)
        {
            cout<<"YES\n";
            continue;
        }
        ll netshift=0;
//        for(auto it:arr)
//            cout<<it.first<<" "<<it.second<<"\n";
        for(ll i=0;i<n;i++)
        {
            if(arr[i].second==i)
                continue;
            else
            {

                if(arr[i].second<i)
                {

                    ll af=0;
                    for(ll j=arr[i].second;j<i;j++)
                    {
                        if(pos.find(j)==pos.end())
                        {
                            af=1;
//                            break;
                        }
                    }
                    if(af)
                    {
                        flag=1;
//                        break;
                    } else
                    {
                        for(ll j=i+1;j<n;j++)
                        {
                            if(arr[j].second>arr[i].second&&arr[j].second<=i)
                                arr[j].second--;
                        }
                        arr[i].second=i;

                    }
                } else
                { ll af=0;
                    for(ll j=arr[i].second-1;j>=i;j--)
                    {
                        if(pos.find(j)==pos.end())
                        {
                            af=1;
//                            break;
                        }
                    }
                    if(af)
                    {
                        flag=1;
//                        break;
                    } else
                    {
                        for(ll j=i+1;j<n;j++)
                        {
                            if(arr[j].second<arr[i].second&&arr[j].second>=i)
                                arr[j].second++;
                        }
                        arr[i].second=i;

                    }

                }



            }

            for(ll i = 0 ; i < 10 ; i++) {
                ll x = 1;
            }
//cout<<flag<<"\n";

        }
        if(flag == 0)
            cout<<"YES\n";
        else cout<<"NO\n";

        for(ll i = 0 ; i < 10 ; i++) {
            ll x = 1;
        }

    };

    return 0; }
