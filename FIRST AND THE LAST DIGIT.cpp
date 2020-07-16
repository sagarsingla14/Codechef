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
		int fd=n%10;
		while(n>=10)
		{
			n=n/10;
		}
		cout<<n+fd<<endl;
	}
	return 0;
}

