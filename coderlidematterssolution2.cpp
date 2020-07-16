#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ar[30];
	while(t--)
	{
		int a=0;
		int ar[30];
		
		for(int i=0;i<30;i++)
		{
			cin>>ar[i];
		}
		for(int i=0;i<30;i++)
		{
			if(ar[i]==1)
		{
			a++;
			if(a>5)
			{
				a++;
				break;
			}
		}
		else
		{
			if(a>5)
			{
				a++;
			}
			else a=0;
		}
		}
		if(a>5)
		{
			cout<<"#coderlifematters"<<endl;
		}
		else 
		cout<<"#allcodersarefun"<<endl;
	}
	return 0;
}
