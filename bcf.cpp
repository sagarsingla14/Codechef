#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int l[n]={0};
        int r[n]={0};
        if(arr[0]>=0)
        {
            l[0]=1;
        }
        if(arr[n-1]>=0)
        {
            r[n-1]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=i&&l[i-1])
            {
                l[i]=1;
            }
        }
        int x=1;
        for(int i=n-2;i>=0;i--,x++)
        {
            if(arr[i]>=x&&r[i+1])
            {
                r[i]=1;
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(l[i]&&r[i])
            {
                flag=true;
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(!flag)
        {
            cout<<"No"<<endl;
        }

    }
    return 0;
}
