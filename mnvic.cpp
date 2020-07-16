#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define LL long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        LL n, s, k;
        cin >> n >> s >> k;
        unordered_set<LL> closed(k);
        closed.clear();
        for (int i = 0; i < k; i++)
        {
            int c;
            cin >> c;
            closed.insert(c);
        }

        if (closed.find(s) == closed.end())
        {
            // cout << "h";
            cout << 0 << endl;
            continue;
        }

        //below s
        LL belowans = INT_MAX;
        for (LL i = s - 1; i >= 1; i--)
        {
            if (closed.find(i) == closed.end()){
                // cout << i << " b" << endl;
                belowans = s - i;
                break;
            }

        }

        if (belowans == 1)
        {
            cout << 1 << endl;
            continue;
        }

        LL abans = INT_MAX;
        for (LL i = s + 1; i <= n; i++)
        {
            if (closed.find(i) == closed.end()){
                //   cout << i << " a" << endl;
                abans = i - s ;
                break;
            }

        }

        // cout << belowans << " " << abans << " ";
        cout << min(belowans, abans) << endl;
    }
    for(LL i = 0 ; i < 1000 ; i++) {
        LL x = 0;
        // [lag remove]
    }

    return 0;
}
