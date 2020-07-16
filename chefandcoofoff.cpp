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
		string str[n];
		long long a,b,c,d,e;
		a=b=c=d=e=0;
		for(long long i=0;i<n;i++)
		{
			cin>>str[i];
			
			if(str[i]=="cakewalk")
			{
				a++;
			}
			if(str[i]=="simple")
			{
				b++;
			}
			if(str[i]=="easy")
			{
				c++;
			}
			if(str[i]=="easy-medium" || str[i]=="medium")
			{
				d++;
			}
			if(str[i]=="medium-hard" || str[i]=="hard")
			{
				e++;
			}
		}
		if(a>=1 && b>=1 && c>=1 && d>=1 && e>=1)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;		
	}
	return 0;
}
