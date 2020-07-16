#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int b=0;
		int count=0, f=0;;
		string s;
		cin>>s;
		for(int i=0;i<=s.length()-4 && f==0;i++)
		{
count=0;
			for(int j=i;j<i+4;j++)
			{
				if(s[j]=='c'&&s[j+1]=='h'&&s[j+2]=='e'&&s[j+3]=='f')count++;  
				if(s[j]=='c'&&s[j+1]=='e'&&s[j+2]=='h'&&s[j+3]=='f')count++;  
				if(s[j]=='c'&&s[j+1]=='f'&&s[j+2]=='e'&&s[j+3]=='h')count++;  
				if(s[j]=='c'&&s[j+1]=='h'&&s[j+2]=='f'&&s[j+3]=='e')count++;  
				if(s[j]=='c'&&s[j+1]=='e'&&s[j+2]=='f'&&s[j+3]=='h')count++;  
				if(s[j]=='c'&&s[j+1]=='f'&&s[j+2]=='h'&&s[j+3]=='e')count++;  
				
				if(s[j]=='h'&&s[j+1]=='c'&&s[j+2]=='e'&&s[j+3]=='f')count++;  
				if(s[j]=='h'&&s[j+1]=='c'&&s[j+2]=='f'&&s[j+3]=='e')count++;  
				if(s[j]=='h'&&s[j+1]=='e'&&s[j+2]=='f'&&s[j+3]=='c')count++;  
				if(s[j]=='h'&&s[j+1]=='e'&&s[j+2]=='c'&&s[j+3]=='f')count++;  
				if(s[j]=='h'&&s[j+1]=='f'&&s[j+2]=='e'&&s[j+3]=='c')count++;  
				if(s[j]=='h'&&s[j+1]=='f'&&s[j+2]=='c'&&s[j+3]=='e')count++;  
				
				if(s[j]=='e'&&s[j+1]=='c'&&s[j+2]=='h'&&s[j+3]=='f')count++;  
				if(s[j]=='e'&&s[j+1]=='c'&&s[j+2]=='f'&&s[j+3]=='h')count++;  
				if(s[j]=='e'&&s[j+1]=='h'&&s[j+2]=='f'&&s[j+3]=='c')count++;  
				if(s[j]=='e'&&s[j+1]=='h'&&s[j+2]=='c'&&s[j+3]=='f')count++;  
				if(s[j]=='e'&&s[j+1]=='f'&&s[j+2]=='h'&&s[j+3]=='c')count++;  
				if(s[j]=='e'&&s[j+1]=='f'&&s[j+2]=='c'&&s[j+3]=='h')count++;  
				
				if(s[j]=='f'&&s[j+1]=='c'&&s[j+2]=='h'&&s[j+3]=='e')count++;  
				if(s[j]=='f'&&s[j+1]=='c'&&s[j+2]=='e'&&s[j+3]=='h')count++;  
				if(s[j]=='f'&&s[j+1]=='h'&&s[j+2]=='e'&&s[j+3]=='c')count++;  
				if(s[j]=='f'&&s[j+1]=='h'&&s[j+2]=='c'&&s[j+3]=='e')count++;  
				if(s[j]=='f'&&s[j+1]=='e'&&s[j+2]=='h'&&s[j+3]=='c')count++;  
				if(s[j]=='f'&&s[j+1]=='e'&&s[j+2]=='c'&&s[j+3]=='h')count++;  
				
			}
				if(count>0){
		cout<<"lovely"<<" "<<count<<endl;
f=1;
break;}
		else
		cout<<"normal"<<endl;;
	
	}
		}
	return 0;
	}



