#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	int l=0;
	while(n--)
	{
		int t;
		cin>>t;
			if(t%k==0)
			{
				l=l+1;
			}
	}
	cout<<l<<endl;
	
	return 0;
}
