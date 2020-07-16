#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long arr[n]={0};
		for(long long i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		vector <int> v;
		for(long long i=0;i<n-1;i++)
		{
			for(long long j=i+1;j<n;j++)
			{
				v.push_back(arr[i]*arr[j]);
			}
		}
		long long count=0;
		for(long long i=0;i<v.size();i++)
		{
			for(long long j=0;j<n;j++)
			{
				if(arr[j]==v[i])
				{
					count++;
					break;
				}
			}
		}
		if(count==v.size())
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
