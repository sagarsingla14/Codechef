#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
#define inf 1100000000
#define pi acos(-1.0)
#define maxn 1005
int dp[2][maxn][10];  //滚动数组,dp[i][j]表示前i行，选了j个，当前行状态为state的最大总价值
int sczt[20]={0,7,6,4,5,4,1,0,3,2,0,1,0};  //这里是上一层的状态
int jia[20]= {0,3,2,2,2,1,2,1,2,1,1,1,0};  //这里是用这个状态铺砖时，增加了多少砖块
int zt[20]=  {0,7,6,7,5,4,7,6,3,2,3,1,0};  //这里是当前行的状态
int a[maxn][maxn];
int getsum(int h,int idx) //这里算的是增加多少价值
{
    int i,j;
    if(idx==1)return a[h][1]+a[h][2]+a[h][3]+a[h-1][1]+a[h-1][2]+a[h-1][3];
    if(idx==2)return a[h][1]+a[h][2]+a[h-1][1]+a[h-1][2];
    if(idx==3)return a[h][1]+a[h][2]+a[h][3]+a[h-1][1];
    if(idx==4)return a[h][1]+a[h][3]+a[h-1][1]+a[h-1][3];
    if(idx==5)return a[h][1]+a[h-1][1];
    if(idx==6)return a[h][1]+a[h][2]+a[h][3]+a[h-1][3];
    if(idx==7)return a[h][1]+a[h][2];
    if(idx==8)return a[h][2]+a[h][3]+a[h-1][2]+a[h-1][3];
    if(idx==9)return a[h][2]+a[h-1][2];
    if(idx==10)return a[h][2]+a[h][3];
    if(idx==11)return a[h][3]+a[h-1][3];
    if(idx==12)return 0;


}


int main()
{
    int n,k,i,j,len,val,state,t;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++){
            for(j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(j=1;j<=k;j++){
            for(state=0;state<8;state++){
                dp[1][j][state]=-inf;
            }
        }

        dp[1][0][0]=0;
        dp[1][1][6]=a[1][1]+a[1][2];
        dp[1][1][3]=a[1][2]+a[1][3];


        int tot=1;
        for(i=2;i<=n;i++){
            for(j=0;j<=k;j++){
                for(state=0;state<8;state++){
                    dp[1^tot][j][state]=-inf;
                }
            }


            for(j=0;j<=k;j++){
                for(t=1;t<=12;t++){  //这里枚举的是12种这一行与上一行可能的状态，即第一个格子里竖着放，第一个格子横着放，第一个格子不放等状态
                    for(state=0;state<8;state++){  //枚举上层状态
                        if((sczt[t]&state)==0 ){
                            if(j+jia[t]<=k){
                                dp[1^tot][jia[t]+j ][zt[t] ]=max(dp[1^tot][jia[t]+j ][zt[t] ],dp[tot][j][state]+getsum(i,t) );
                            }
                        }
                    }
                }
            }
            tot=1^tot;
        }
        int maxx=dp[tot][k][0];
        for(state=1;state<8;state++){
            maxx=max(maxx,dp[tot][k][state] );
        }
        printf("%d\n",maxx);
    }
    return 0;
}
