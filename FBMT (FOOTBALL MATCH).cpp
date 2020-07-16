#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int t1=0,t2=0;
		string temp1,temp2;
		int i=1;
		while(n--)
		{
			string str;
			cin>>str;
			while(i)
			{
				temp1=str;
				i--;
			}
			if(temp1==str)
			{
				t1++;
			}
			else
			{
				temp2=str;
				t2++;
			}
		}
		if(t1>t2)
		{
			cout<<temp1<<endl;
		}
		if(t1<t2)
		{
			cout<<temp2<<endl;
		}
		if(t1==t2)
		{
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}
