#include <iostream>
using namespace std;
 
int main()
{
 
 int T;
 cin>>T;
 while(T--)
 {
     
  int n;
  cin>>n;
  int minC1=3000, maxD1=0, minC2=3000, maxD2=0, minC3=3000, maxD3=0, c ,l , x;
  for(int i=0;i<n;i++)
  {
        cin>> c >>   l>>x;
        if (l ==1)
        {
            if (x > maxD1)
            { maxD1 = x; minC1 = c;}
            
            if(x == maxD1)
            {
             if (minC1 >c)
             {
                 minC1 =c;
                 maxD1 =x;
             }
            }
            if(x< maxD1)
            {
            	maxD1;
            	minC1;
			}
        }
        else if (l==2)
        {
             if (x > maxD2)
            { maxD2 = x; minC2 = c;}
            
            if(x == maxD2)
            {
             if (minC2 >c)
             {
                 minC2 =c;
                 maxD2 =x;
             }
            }
             if(x< maxD1)
            {
            	maxD2;
            	minC2;
			}
            
        }
        else{
            if (x > maxD3)
            { maxD3 = x; minC3 = c;}
            
            if(x == maxD3)
            {
             if (minC3 >c)
             {
                 minC3 =c;
                 maxD3 =x;
             }
            }
             if(x< maxD1)
            {
            	maxD3;
            	minC3;
			}
            
        }
        
  }
  
  cout<< maxD1 << " " << minC1<<endl;
  cout<< maxD2 << " " << minC2<<endl;
  cout<< maxD3 << " " << minC3<<endl;
     
 }
  
}
