#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;

int main() {
	fast_io
    ll t;
	cin >> t;
	while(t--) {
      cin >> str;
      ll n = str.length();

      ll maxcount = 0;
      vector<ll> occurences(10);

      for(ll i = 0; i<n; i++) {
        ll temp = s[i] - '0';
        occurences[temp]++;
      }

      ll maxoccurence = 0;

      for(ll i = 0; i<=9; i++)
        maxoccurence = max(maxoccurence, occurences[i]);

      maxoccurence = n - maxoccurence;
      for(ll i = 0; i<=9; i++)
      {
        for(ll j = 0; j<=9; j++)
        {
            if(i == j)
              continue;

            bool ioccur = false, joccur= false;
            ll count = 0;
            for(ll x = 0; x<n; x++)
            {
                ll temp = s[x] - '0';

                if(temp == i)
                {
                    ioccur = true;
                }

                if(temp == j)
                {
                  if(ioccur)
                      count++;

                  ioccur = false;
                }
            }

            maxcount = max(maxcount, count);
        }
      }

      maxcount = n - 2*maxcount;

      cout << min(maxoccurence, maxcount) << "\n";
	}

  return 0;

}
