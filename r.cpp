#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;

            ll a[n];
			ll temp = n;
			map<ll,ll> b;
			map<ll,ll> c;
			ll i = 0 ;
			while(temp--) {
				cin >> a[i];
				i++;
			}

            if(n==1) {
                cout << -1 << endl;
                continue;
            }

            //memset(occ,0,sizeof occ);
            ll ans=INT_MAX;


            for(int r=0;r<n;r++){
                c[a[r]]++;
                if(c[a[r]]>1){
                    ans=min(ans,r-b[a[r]]+1);
                    b[a[r]]=r;
                    c[a[r]]--;
                }
				if(c[a[r]]==1)b[a[r]]=r;

            }

            if(ans==INT_MAX)
            {
                cout<<"-1"<<endl;
            }
            else{
                cout<<ans<<endl;
            }

        }

        return 0;
    }
