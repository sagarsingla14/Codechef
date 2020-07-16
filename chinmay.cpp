#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<unordered_set>
#include<map>
#include<deque>
#include<cstring>
#include<utility>
#include<queue>
#include<string>
#include<iomanip>
#include<unordered_map>
#include<list>
using namespace std;
#define int /*unsigned*/long long
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define LM LONG_MAX
#define LS LONG_MIN
#define ccM 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
int max(int b,int a){if(b>a)return b;else return a;}
int min(int b,int a){if(b<a)return b;else return a;}
int Abs(int b){return max(b,-b);}
void print(vector<pair<int,int> >&v){fr(i,v.size())cout<<v[i].F<<" "<<v[i].S<<endl;cout<<endl;}
void print(int arr[],int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}
bool sortbysec(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){return (a.first.second < b.first.second);}
int32_t main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> >v;
        for(int i=0;i<n+1;i++)
        {
            vector<int>p;
            v.pb(p);
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        if(m%2==0)//IF NUMBER OF EDGES EVEN
        {
            for(int i=1;i<=n;i++)cout<<1<<" ";
            cout<<endl;
        }
        else// IF ODD
        {
            int fl=0;
            int f=-1;
            for(int i=1;i<=n;i++)
            {
                if(v[i].size()%2==1)
                {
                    f=i;
                    fl=1;
                    break;
                }
            }
            if(fl)// IF THERE IS ATLEAST ONE NODE WITH ODD DEGREE
            {
                for(int i=1;i<=n;i++)
                {
                    if(f==i)cout<<2<<" ";
                    else cout<<1<<" ";
                }
            }
            else//IF ALL THE NODES HAVE EVEN DEGREE
            {
                int g=-1,f=-1;
                for(int i=1;i<=n;i++)
                {
                    if(v[i].size()>0){
                        g=i,f=v[i][0];break;// PICKING UP 2 ADJACENT NODES WITH EVEN DEGREE SUCH THAT THEY HAVE A COMMON EDGE
                    }
                }
                for(int i=1;i<=n;i++){
                    if(i==f)cout<<2<<" ";
                    else if(i==g)cout<<3<<" ";
                    else cout<<1<<" ";
                }
            }
            cout<<endl;
        }

    }
}
