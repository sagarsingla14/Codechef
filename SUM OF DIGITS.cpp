#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int l=str.length();
		int sum=0;
		for(int i=0;i<l;i++)
		{
			int n=str[i]-48;
			sum=sum+n;
		}
		cout<<sum<<endl;
	}
	return 0;
}
