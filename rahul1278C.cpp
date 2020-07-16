#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++) cin>>v[i];

        map<int,int> m;
        int diff=0;
        m[diff]=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)
            {
                diff++;
                m[diff]=i;
            }
            else
            {
                diff--;
                m[diff]=i;
            }
        }
        map <int,int> :: iterator itr;
        for(itr = m.begin() ; itr!= m.end() ; itr++) {
            cout << itr -> first << " " << itr -> second << endl;
        }

        diff=0;
        int ans=min(2*n,2*n-m[0]-1);
        cout << ans << endl;
        for(int i=2*n-1;i>=n;i--)
        {
            if(v[i]==1) diff++;
            else diff--;

            cout << "diff " << diff << endl;
            if(m.find(-diff)!=m.end())
            {
                ans=min(ans,i-m[-diff]-1);
            }
            cout << ans << endl;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
