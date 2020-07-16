#include<bits/stdc++.h>

// #define count1 __builtin_popcount
#define int long long
#define pb push_back
#define pii pair<int,int>
#define ppii pair<pii,pii>
#define fr(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define ccM 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
long double pi = 3.14159265358979323;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int max(int b,int a){if(b>a)return b;else return a;}
int min(int b,int a){if(b<a)return b;else return a;}
int Abs(int b){return max(b,-b);}
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return a.second<b.second;}
int ans=1e13;

void convert10tob(int N,int b,string& s)
{
     if (N==0)
        return;

     int x = N%b;
     N/=b;
     if (x<0)
        N+=1;

     convert10tob(N,b,s);
     s+=char((x<0?x+(b*-1):x)+'0');
     return;
}


int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        map<int,int>pp;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            pp[arr[i]]++;
        }
        if(pp.size()!=n)
        {
            if((pp.begin())->F!=0){
                cout<<"NO"<<endl;
                continue;
            }
            else if((pp.begin())->F!=0)
            {
                cout<<"YES"<<endl;
                continue;
            }
        }
        map<int,int>mp;
        int x=*max_element(arr,arr+n);
        string po="";
        convert10tob(x,k,po);
        int jp=po.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)continue;
            string s="";
            convert10tob(arr[i],k,s);
            //reverse(s.begin(),s.end());
            //cout<<s<<endl;
            while(jp!=s.size())
            {
                s='0'+s;
            }
            //cout<<s<<endl;
            for(int j=0;s[j];j++){
                if(s[j]=='0')continue;
                mp[j]+=int32_t(s[j]-'0');
            }
        }
        int fl=0;
        //cout<<mp.size()<<endl;
        for(auto x:mp)
        {
            //cout<<x.S<<endl;
            if(x.S>1)fl=1;
        }
        if(fl)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
}
