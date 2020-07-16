#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;

	
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		long long ca,cb;
		ca=a%10;
		cb=b%10;
		if(ca+cb>=10)
		{
			cout<<(a+b-10)<<endl;
		}
		
		else cout<<a+b<<endl;
	}
	
	else return 0;
}
