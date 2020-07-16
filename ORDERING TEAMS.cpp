#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int arr[3][3]={0};
		int sums[3];
		int	sum=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>arr[i][j];
				sum=sum+arr[i][j];
			}
				sums[i]=sum;
		}
		
			if(arr[0][0]>=arr[1][0] && arr[0][1]>=arr[1][1] && arr[0][2]>=arr[1][2] && sums[0]>sums[1])
			{
			if((arr[1][0]>=arr[2][0] && arr[1][1]>=arr[2][1] && arr[1][2]>=arr[2][2] && sums[1]>sums[2]) || (arr[2][0]>=arr[1][0] && arr[2][1]>=arr[1][1] && arr[2][2]>=arr[1][2] && sums[2]>sums[1]))
			{
				cout<<"yes"<<endl;
			}
			else cout<<"no"<<endl;
			}
			
			if(arr[0][0]<=arr[1][0] && arr[0][1]<=arr[1][1] && arr[0][2]<=arr[1][2] && sums[0]<sums[1])
			{
			if((arr[1][0]>=arr[2][0] && arr[1][1]>=arr[2][1] && arr[1][2]>=arr[2][2] && sums[1]>sums[2]) || (arr[2][0]>=arr[1][0] && arr[2][1]>=arr[1][1] && arr[2][2]>=arr[1][2] && sums[2]>sums[1]))
			{
				cout<<"yes"<<endl;
			}
			else cout<<"no"<<endl;
			}
			else
			cout<<"no"<<endl;
	}		
		return 0;
	}
	


