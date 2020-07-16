#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool uniquePaths(vector<vector<bool>> v, int n) {
        int m = 2;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));

        if(v[m-1][n-1])
            dp[m-1][n-1] = true;

        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue;
                if(v[i][j])
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
            }
        }

        return dp[0][0];

    }

int main()
{
    ll n,q;
    cin >> n >> q;

    vector<vector<bool>> v(3,vector<bool>(n+1,true));

    for(int i = 0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;

        v[x-1][y-1] = !v[x-1][y-1];

        if(uniquePaths(v,n))
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;

    }

}
