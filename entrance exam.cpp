#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,e,m,a,output,l,sum=0;
		cin>>n>>k>>e>>m;
		long long temp;
		long long arrsum[n-1];
		for(long long i=0;i<n-1;i++)
		{
			sum=0;
			for(long long j=0;j<e;j++)
			{
				cin>>temp;
				sum=sum+temp;
			}
			arrsum[i]=sum;
		}
		
		sum=0;
	
		  for(long long i=0; i<e-1; i++)
        {
            cin>>temp;
            sum=sum+temp;
        }		

			for(long long i=0;i<n;i++)
		{
			for(long long j=i+1;j<n;j++)
			{
				if(arrsum[i]<arrsum[j])
				{
					a=arrsum[j];
					arrsum[j]=arrsum[i];
					arrsum[i]=a;			
				}
			}
		}	
		
		output=arrsum[k-1]-sum+1;
		
		if(output<0)
		{
			cout<<0<<endl;
		}
		else
		{
		if(output<m)
		{
			cout<<output<<endl;
		}
		else
		{
		cout<<"Impossible"<<endl;
		}
		}
	}
	return 0;
}
