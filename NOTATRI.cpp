#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	while(1)
	{
		long long n;
		cin>>n;
		if(n==0)
		{
			break;
		}
		else
		{
		long long arr[n]={0};
		for(long long i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,greater<long long>());
		
		long long count=0;
		for(long long i=0;i<n-2;i++)
		{
			for(long long j=i+1;j<n-1;j++)
			{
				for(long long k=j+1;k<n;k++)
				{
					if(arr[i]>arr[j]+arr[k] || arr[i]<arr[j]-arr[k])
					{
						count++;
					}
				}
			}
		}
		cout<<count<<endl;
		}
	}
	return 0;
}
