/*input
7 24 21 23
16 17 14 20 20 11 22

*/

/*
                                                    ______________
                                                          |       )
                                                          |   )   /
                                                          |______/
                                                    |     |      \
                                                    |     |   )   \
                                                    |_____|_______)

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
int mod = 1000000007;
const int inf = 1034567891;
const ll LL_INF = 1234567890123456789ll;
#define PI 3.14159265
#define endl '\n'
#define F first
#define S second
#define debug(x) cout << #x << " = " << x << endl;
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define out(container) for (auto it : container) cout << it << " "; cout << endl;


template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
  int x = 1 % mod;
  while(b){
    if(b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int n, h, l, r;
vector<int> vec;
const int N = 3000;
int dp[N][N];

bool isGood(int hr) {
  if (hr >= l && hr <= r) return true;
  return false;
}
int get(int cur, int v) {
  cur += v;
  cur %= h;
  return cur;
}

int fun(int ind, int cur) {
  if (ind == n) return 0;
  if (dp[ind][cur] != -1) return dp[ind][cur];
  int ans = 0;
  ans = max(ans, isGood(get(cur, vec[ind] - 1)) + fun(ind + 1, get(cur, vec[ind] - 1)));
  ans = max(ans, isGood(get(cur, vec[ind])) + fun(ind + 1, get(cur, vec[ind])));
  return dp[ind][cur] = ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> h >> l >> r;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.pb(v);
  }
  memset(dp, -1, sizeof(dp));
  int ans = fun(0, 0);
  cout << ans << endl;


  return 0;
}