#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ii> vii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr(be, en) for(int i = be; i <= en; i++)
ll mod = LLONG_MAX;
ll power(ll a, ll b)
{
	if(b == 0) return 1;
	ll ans = power(a, b/2);
	ans = (ans*ans)%mod;
	if(b%2) ans*=a;
	return ans%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int t, n, k;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> s;
		sort(s.begin(), s.end());
		if(k == 1)
		{
			cout << s << "\n";
			continue;
		}
		bool flag = 1;
		for(int i = 1; i < k && flag; i++) if(s[i] != s[i - 1]) flag = 0;
		if(!flag)
		{
			cout << s[k - 1] << "\n";
			continue;
		}
		vs ans(k + 1);
		for(int i = 0; i < n; i++)	ans[i%k].pb(s[i]);
		ans[k].pb(s[k - 1]);
		for(int i = k; i < n; i++) ans[k].pb(s[i]);
		string final_ans = ans[0];
		for(int i = 1; i < k; i++) if(final_ans < ans[i]) final_ans = ans[i];
		cout << min(final_ans, ans[k]) << "\n";
		// vi f(27, 0);
		// for(int i = 0; i < s.size(); i++) f[s[i] - 'a']++;
		// for(int i = 0; i < 27 && flag; i++) if(f[i]%k) flag = 0;
		// if(flag)
		// {
		// 	for(int i = 0; i < n; i+=k) cout << s[i];
		// 	cout << "\n";
		// 	continue;
		// }
		// flag = 1;
		// bool ch1 = 0;
		// string ans1;
		// for(int i = 0; i < 26 && flag; i++)
		// {
		// 	if(f[i]%k)
		// 	{
		// 		if(!ch1) ch1 = 1;
		// 		else flag = 0;
		// 	}
		// 	else
		// 	{
		// 		for(int j = 1; j <= f[i]/k; j++) ans.pb(char('a' + i));
		// 	}
		// }
		// if(flag)
		// {
		// 	cout << ans << "\n";
		// 	continue;
		// }
		// cout << s[k - 1];
		// for(int i = k; i < n; i++) cout << s[i];
		// cout << "\n";
		// continue;
	}
}
