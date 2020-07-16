#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int a=0;
		int l=str.length();
		for(int i=0;i<str.length();i++)
		{
			if((str[i]=='1' && str[i+1]=='0') || (str[i]=='0' && str[i+1]=='1'))
			{
				a++;
			}
		}
		if((str[0]=='1' && str[l-1]=='0') || (str[l-1]=='1' && str[0]=='0') )
		{
			a++;
		}
		if(a>2)
		{
			cout<<"non-uniform"<<endl;
		}		
		else
		 {
		   cout << "uniform"<<endl;		
		}
	}
}

