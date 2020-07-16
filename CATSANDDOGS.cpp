#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,kitnepairkamsekam;
	cin>>t;
	while(t--)
	{
		long long int c,d,l;
		cin>>c>>d>>l;
		long long int maxlegs=4*c+4*d;
		if(l%4==0)
		{
		if(c>=2*d)
		{
			long long int kitnibili=c-2*d;
			kitnepairkamsekam=kitnibili*4+d*4;

			if(l<=maxlegs && l>=kitnepairkamsekam)
			{
				cout<<"yes"<<endl;
			}
			else cout<<"no"<<endl;
		
		}
		else if(c<2*d)
		{
			kitnepairkamsekam=d*4;
			if(l<=maxlegs && l>=kitnepairkamsekam)
			{
				cout<<"yes"<<endl;
			}
			else cout<<"no"<<endl;
		}
		}
		else 
		cout<<"no"<<endl;
	}
	return 0;
}
