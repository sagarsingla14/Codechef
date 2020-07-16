#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll t;
	cin>>t;
	for(ll i = 0 ; i < t ; i++){
		string s;
		cin >> s;
		ll ans=0;
		ll val = 0;
		ll l = s.length();
		for(ll i=0 ; i < l ; i++){
			if(s[i] == 'R'){
				val = 0;
			}
			else{
				val++ ;
			}
			if(ans < val){
				ans = val;
			}
		}
		if(val > ans) {
			ans = val;
		}
		ans ++;
		cout << ans << endl;
	}
	return 0;
}
