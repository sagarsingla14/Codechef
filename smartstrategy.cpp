#include <iostream>
using namespace std;
int main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	long long n,q;
	cin>>n>>q;
	long ar1[n];
	long ar2[q];
	long ar3[q]={0};
	long long p;
	
	for(long long i=0;i<n;i++)
	{
		cin>>ar1[i];
		p=p*ar1[1];
	}
	for(long long i=0;i<q;i++)
	{
		cin>>ar2[i];
	}
	
	for(long long i=0;i<q;i++)
	{
		ar3[i]=ar2[i]/p;
	}
	
	for(long long i=0;i<q;i++)
	
		cout<<ar3[i]<<endl;
	
	}		
	return 0;
}

