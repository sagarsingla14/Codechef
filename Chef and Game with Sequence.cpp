#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int even=0,odd=0;
		int n;
		cin>>n;
		while(n--)
		{
			int x;
			cin>>x;
			if(x%2==0)
			{
				even++;
			}
			else
			{
				odd++;
			}
		}
		if((odd%2==0 && even>=0) || (odd==0 && even>=0) || (odd==1 && even==0))
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"2"<<endl;
		}
	}
	return 0;
}
