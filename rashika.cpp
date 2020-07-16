#include <iostream>
using namespace std;
 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{ 
		int m,level1=0,level2=0,level3=0,j,k,a=0,b=0,c=0;
	  cin>>m;
	  int city[m][3];
	  for( k=0;k<m;k++)
	  { for ( j=0;j<3;j++)
	    cin>>city[k][j];
	  }
	  for(k=0;k<m;k++)
	  { switch( city[k][1])
	    {case(1): if( city[k][2]>=level1)
	              
	             	{
	             		if(city[k][2]==level1)
	               a=(city[k][0]>a?a:city[k][0]);
	               else
	               {a=city[k][0];}
	               level1=city[k][2];
	              }
	              
	    break;
	    case(2): if(city[k][2]>=level2)
	              {
	               if(city[k][2]==level2)
	               b=(city[k][0]>b?b:city[k][0]);
 
	               else
	              { b=city[k][0];}
	               level2=city[k][2];
	               }
	              
	    break;
	    case(3): if( city[k][2]>=level3)
	             { 
	               if(city[k][2]==level3)
	               c=(city[k][0]>c?c:city[k][0]);
	               else
	              { c=city[k][0];}
	               level3=city[k][2];
	             }
	             
	    break;
	    }
	   }
	   cout<<level1<<" "<<a<<endl<<level2<<" "<<b<<endl<<level3<<" "<<c<<endl;
	 }
 
	return 0;
}
