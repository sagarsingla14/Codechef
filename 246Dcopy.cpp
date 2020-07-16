#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 100010
char s[N];
int f[N],id[N],ans,dp[N];
int main()
{
	scanf("%s",s);
	int n = strlen(s);
	for(int i=1,j;i<n;i++)
	{
		for(j=f[i];j&&s[i]!=s[j];j=f[j]);
		f[i+1] = s[i]==s[j]?j+1:0;
	}
	for(int i=n;i>=0;i--)
	{
		dp[i]++;
		dp[f[i]]+=dp[i];
	}

	for(int i = 0 ; i <= n ; i++) {
		cout << f[i] << " ";
	}
	cout << endl;
	id[0]=n;
	for(int i=f[n];i;i=f[i])
		id[++ans] = i;
	printf("%d\n",ans+1);
	for(int i=ans;i>=0;i--)
		printf("%d %d\n",id[i],dp[id[i]]);
	return 0;
}
