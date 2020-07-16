#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n]={0};
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int op=0;
		if(k%2==1)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]%k>=(k/2)+1)
				{
					op=op+k-(arr[i]%k);
				}
				else 
				{
					op=op+(arr[i]%k);
				}
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]%k>(k/2))
				{
					op=op+(k-arr[i]%k);
				}
				else
				{
					op=op+(arr[i]%k);
				}
			}
		}
		cout<<op<<endl;
	}
	return 0;
}
