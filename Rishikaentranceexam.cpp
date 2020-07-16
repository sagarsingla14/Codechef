#include <iostream>
using namespace std;
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
{
		int n,k,e,m,sum1=0,f=0,sum=0,s=0;
		scanf("%d%d%d%d",&n,&k,&e,&m);
		int arr[n-1];
		for(int j=0;j<=n-2;j++)
		arr[j]=0;
		for(int i=0;i<n-1;i++)
		{
			int l=0,a[e] ;
			for(int j=0;j<e;j++)
			{
			int y;
			scanf("%d",&y);
			a[j]=y;
			}
				for(int h=0;h<e;h++)
			      sum1+=a[h];
			      arr[i]=sum1;
			 
			 sum1=0;
	        }
				
			
		for( int i=1;i<=e-1;i++)
            {
			int u;
			scanf("%d",&u);
			sum+=u;
           }
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n-1;j++)
{
if(arr[i]<arr[j])
{
int temp=0;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
f=arr[k-1]-sum+1;
if(f>0&&f<=m)
cout<<f<<endl;
else if(f<=0)
cout<<0<<endl;
else
cout<<"Impossible"<<endl;
t--;
 
}
	return 0;
}
