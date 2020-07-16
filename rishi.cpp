#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
	      ll n;
	      cin>>n;
	      string a;
	      cin>>a;
	      ll s=-1,e=-1,flag=0;
	      for(ll i=0;i<n;i++){
      		if(a[i]=='1'){
      			if(flag==0){
      				s=i;
      				e=i;
      				flag=1;
      			}
      			else{
      				e=i;
      			}
      		}
      	}
		ll ans = -1;
      	ans=max(max(e,n-1-e),max(s,n-1-s));
      	ans++;
      	if(s!=-1)
		cout<<2*ans;
      	else
		cout<<n;
		cout<<endl;
	}
}
