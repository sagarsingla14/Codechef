#include <bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;
int main () {
	ll t;
	cin>>t;
	ll a=1,b=2,c=3,d=4;
	ll arr[100001] = {0};

	for(ll i =1 ; i < 100001; i++){
		ll p = (a%m * b%m);
		p %= m;
		p = (p%m * c%m);
		p %= m;
		p = (p%m * d%m);
		p %= m;
		arr[i] = p%m;
		a++;
		b++;
		c++;
		d++;
	}

	ll sum[100001] = {0};
	for(ll i = 1; i < 100001 ; i++){
		sum[i] += sum[i];
		sum[i] %= m;
	}
	while(t--){
		ll l,r;
		cin>>l>>r;
		ll ans = (sum[r]%m - sum[l-1]%m);
		ans %= m;
		cout<<ans<<endl;
	}
	return 0;
}