#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		string str[100];
		string str1[50][50];
		cin>>n>>k;
		int arr[50];
		
		
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
		}
		for(int i=0;i<k;i++)
		{
			cin>>arr[i];
			for(int j=0;j<arr[i];j++)
			{
				cin>>str1[i][j];
			}
		}
		
		for(int i=0;i<n;i++)
		{
		int	find=0;
			for(int j=0;j<k;j++)
			{
				for(int z=0;z<arr[j];z++)
				{
					if(str[i]==str1[j][z])
					{
						cout<<"YES ";
						find=1;
						break;
					}
				}
				if(find==1)
				{
					break;
				}
			}
			if(find==0)
			{
				cout<<"NO ";
			}
		}
		cout<<endl;
				
	}
}
