#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t=1;
	while(t--){
		ll n;
		cin >> n;
		ll arr[n] = {0};
		for(ll i = 0; i < n ; i++){
			cin >> arr[i];
		}
		ll m = 0;
        ll i = 0;
		while(n --){
			cout << arr[i] + m << " ";
			if(arr[i] > 0) {
                m += arr[i];
            }
            i ++;
		}
		cout<<endl;
	}
}
