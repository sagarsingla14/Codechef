#include <iostream>
#include<stdio.h>
using namespace std;

int main() {
	int t,i,n,k,j,a[100];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{   printf("enter the no. of spots:");
	    scanf("%d",&n);
	    printf("enter the position:");
	    for(k=0;k<n;k++)
	    {
	        scanf("%d",&a[k]);
	    }
	    if(n<=6)
	    {
	        printf("NO\n");

	    }
	    else
	    {   int flag=0;
	        for(k=0;k<n;k++)
	        {
	            if(a[k]==1)
                {
                    for(j=k+1;j<k+6;j++)
                    {
                        if(a[j]==1)
                        {   flag=0;
                            printf("NO\n");
                            goto label;
                        }
                        else
                        flag=1;
                    }
                }
	        }
	         label:
	         if(flag==1)
	        {
	            printf("YES\n");

	        }
	    }

	}
	return 0;
}
