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
		int temp=0;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			temp=max(temp,n%i);
		}
		if(temp==0)
		{
			cout<<n<<endl;
		}
		else
		cout<<n-temp<<endl;
	}
	return 0;
}
