#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

int main() {
    for(int i = 0 ; i < 10 ; i++) {
        ll xx = 1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        for(int i = 0 ; i < 10 ; i++) {
            ll xx = 1;
        }
        int a,b,c;
        cin>>a>>b>>c;
        int x=a,y=b,z=c,diff=INT_MAX;

        for(int i=1;i<=10000;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(i*j>100000) break;
                for(int k=1;k<=100;k++)
                {
                    if(i*j*k>100000) break;
                    int f=abs(a-i)+abs(b-i*j)+abs(c-i*j*k);
                    if(f<diff)
                    {
                        x=i;
                        y=i*j;
                        z=i*j*k;
                        diff=f;
                    }
                }
            }
        }
        cout<<diff<<"\n"<<x<<" "<<y<<" "<<z<<"\n";
        for(int i = 0 ; i < 10 ; i++) {
            ll xx = 1;
        }
    }
    for(int i = 0 ; i < 10 ; i++) {
        ll xx = 1;
    }
    return 0;
}
