#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll t , n;

int main() {
    fast_io
	cin >> t;
	while(t--) {
        cin >> n;
        ll arr[n] = {0};

        ll o = 1;
        ll one = 0;
        ll flag = 1;

        for(ll i = 0 ; i < n; i++) {
            cin >> arr[i];
        }

        for(ll i = 0 ; i < n ; i++) {
            if(arr[i]!=1) {
                o = 0;
            }
            if(arr[i] != 1) {
                flag = 0;
            }
            if(flag) {
                one++;
            }
        }

        if(!o) {
            if(one % 2 == 0) {
                cout << "First" << endl;
            }
            else {
                cout << "Second" << endl;
            }
        }

        else {
            if(n % 2 != 0) {
                cout << "First" << endl;
            }
            else {
                cout << "Second" << endl;
            }
        }
	}
  return 0;

}
