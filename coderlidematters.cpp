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
		
		for(int i=0;i<26;i++)
		{
			if(ar[i]==1 && ar[i+1]==1 && ar[i+2]==1 && ar[i+3]==1 && ar[i+4]==1 && ar[i+5]==1)
			{
				a++;
				break;
			}
			else a=0;
		}
			if(a>0)
			{
				cout<<"#coderlifematters"<<endl;
			}
			else
			cout<<"#allcodersarefun"<<endl;
	}
	return 0;
}
