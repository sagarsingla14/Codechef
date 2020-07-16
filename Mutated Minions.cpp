#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,count=0,temp=0;
		cin>>n>>k;
		while(n--)
		{
			int a;
			cin>>a;
			temp=0;
			temp=a+k;
			if(temp%7==0)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
