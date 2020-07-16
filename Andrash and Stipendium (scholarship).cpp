#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long arr[n];
		long double sum=0;
		int flag=0;
		int flag1=0;
		
		for(long long i=0;i<n;i++)
		{
			cin>>arr[i];
			sum=sum+arr[i];	
			if(arr[i]==2)
			{
			flag++;
			}
			if(arr[i]==5)
			{
			flag1++;		
			}		
		}
		float ave=sum/n;
				
		if(ave<4 || flag>0 || flag1==0 )
		{
		
				cout<<"No"<<endl;
		}
		else
		{
				cout<<"Yes"<<endl;
		}
		
	}
	return 0;
} 
