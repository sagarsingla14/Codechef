#include <iostream>
using namespace std;
int factorial(int x)
{
	if(x==0)
	{
		return 1;
	}
	long long fact=factorial(x-1)*x;
		return fact;
		
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long num;
		cin>>num;
		long long facto=factorial(num);
		cout<<facto<<endl;
	}
	return 0;
}
