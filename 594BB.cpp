#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n,m=0,k=0;
    ll ans = 0;
    cin>>n;
    ll l=0,r=n-1;
    ll arr[n] = {0};
    for(ll i=0 ;i<n;i++){
    	cin>>arr[i];
	}
	sort(arr,arr+n);
	while(l<r){
		m+=arr[l++];
		k+=arr[r--];
	}
	ans=(m*m)+(k*k);
	if(l==r){
        ll v1 = ((m+arr[l])*(m+arr[l]))+(k*k);
        ll v2 = (m*m)+((k+arr[l])*(k+arr[l]));
		ans=max(v1, v2);
	}
	cout << ans << endl;;
    return 0;
}
