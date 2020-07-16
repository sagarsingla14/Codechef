#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,f,cl,sl;
		sl=0; cl=0;
		cin>>l>>f;
		char arr[l];
		
		for(int i=0;i<l;i++)
		{
			cin>>arr[i];
		}
		
		for(int i=0;i<l;i++)
		{
			if(arr[i]>='A' && arr[i]<='Z')
			{
				cl=cl+1;
			}
			else if(arr[i]>='a' && arr[i]<='z')
			{
				sl=sl+1;
			}
		}
		
		if(sl>f && cl>f)
		{
			cout<<"none"<<endl;
		}
		
		else if(sl<=f && cl<=f)
		{
			cout<<"both"<<endl;
		}
		
		else if(sl>f && cl<=f)
		{
			cout<<"chef"<<endl;
		}
		
		else if(sl<=f && cl>f)
		{
			cout<<"brother"<<endl;
		}
	}
	return 0;
}
