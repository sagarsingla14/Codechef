#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int m1=0,m2=0,s1=0,s2=0;
	while(t--)
	{
		int r1,r2;
		cin>>r1>>r2;
		s1=s1+r1;
		s2=s2+r2;
		if(s1-s2>0)
		{
			m1=max(m1,s1-s2);
		}
		else
		{
			m2=min(m2,s1-s2);
		}
	}
	if(m1>(-1)*m2)
	{
		cout<<"1"<<" "<<m1<<endl;
	}
	else
	{
		cout<<"2"<<" "<<(-1)*m2<<endl;
	}
	return 0;
}
