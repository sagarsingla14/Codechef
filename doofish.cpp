#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n)for(ll i=0;i<n;i++)
#define forb(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define MOD 1000000007
#define F first
#define S second
#define pii pair<ll,ll>
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}

int main()
{
    tc
    {
        ll n; cin>>n;
        if(n==1)
        {
            cout<<"Hooray\n";
            cout<<1<<endl;
            continue;
        }
        if(n&1)
        {

            cout<<"Boo\n";


        }
        else
        {
            ll mat[n][n]={{0,0},
                          {0,0}};
            for(ll i=0;i<n;i++)
                mat[i][i]=1;
            vector<ll> v;
            for(ll i=2;i<=n;i++)
            {
                v.push_back(i);
            }
            for(ll i=0;i<n;i++)
                mat[0][i]=i+1;

            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n - 1;j++)
                {
                    if(i<j)
                    {
                        ll a=i+j-1;
                        mat[i][j]=v[a%v.size()];


                    }

                    cout << mat[i][j] << "   " ;


                }
                cout << endl;


            }
            for(auto& it: mat)
            {
                for(auto a:it)
                    cout<<a<<"    ";
                cout<<endl;
            }
            cout << endl;
            ll c=1;
//        for(auto it:v)
//            cout<<it<<" ";
//        cout<<endl;
            for(ll i=1;i<n-1;i++)
            {
                mat[i][n-1]=v[c%v.size()];
                c+=2;
//            cout<<c<<endl;
            }
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n;j++)
                {

                    if(i>j)
                    {
                        mat[i][j]=mat[j][i]+n-1;
                    }

                }
            }
            cout<<"Hooray\n";
            for(auto& it: mat)
            {
                for(auto a:it)
                    cout<<a<<"    ";
                cout<<endl;
            }

        }





    };





    return 0;


}
