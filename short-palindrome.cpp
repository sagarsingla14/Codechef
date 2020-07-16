#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

int first[250];
int nxt[2000005];
int s2[2000005];
int zp[2000005], zs[2000005], zq[2000005];
int c[2000005][5];
int scnt[30];
int cnt;
int modulo = (int)1e9 + 7;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < 26; i++) first[i] = -1;
    for (int i = n-1; i >= 0; i--)
    {
       nxt[i] = first[s[i]-'a'];
       first[s[i]-'a'] = i;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
       for (int j = 0; j < 26; j++)
          if (i != j)
          {
             int p1 = first[i];
             int p2 = first[j];
             if (p1 == -1 || p2 == -1) continue;
             cnt = 0;
             while (p1 != -1 || p2 != -1)
             {
                if (p2 != -1 && (p1 == -1 || (p1 > p2)))
                {
                   s2[cnt++] = 0;
                   p2 = nxt[p2];
                }
                else if (p1 != -1 && (p2 == -1 || (p2 > p1)))
                {
                   s2[cnt++] = 1;
                   p1 = nxt[p1];
                }
             }

             zp[0] = (int)(s2[0]==0);
             for (int i = 1; i < cnt; i++)
                zp[i] = zp[i-1] + (int)(s2[i]==0);
             zs[cnt-1] = (int)(s2[cnt-1]==0);
             for (int i = cnt-2; i >= 0; i--)
                zs[i] = zs[i+1] + (int)(s2[i]==0);
             zq[cnt-1] = 0;
             for (int i = cnt-2; i >= 0; i--)
             {
                zq[i] = zq[i+1] + (s2[i]==1?zs[i+1]:0);
                if (zq[i] >= modulo) zq[i] -= modulo;
             }

             for (int i = 1; i < cnt - 1; i++)
                if (s2[i] == 1)
                {
                   ans = ans + (int)(((ll)zp[i-1] * (ll)zq[i+1]) % (ll)modulo);
                   if (ans >= modulo) ans -= modulo;
                }

          }
    c[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
       c[i][0] = 1;
       for (int j = 1; j <= 4; j++)
       {
          c[i][j] = c[i-1][j] + c[i-1][j-1];
          if (c[i][j] >= modulo) c[i][j] -= modulo;
       }
    }
    for (int i = 0; i < 26; i++) scnt[i] = 0;
    for (int i = 0; i < n; i++)
       scnt[s[i]-'a']++;
    for (int i = 0; i < 26; i++)
    {
       ans = (ans + c[scnt[i]][4]);
       if (ans >= modulo) ans -= modulo;
    }
    cout << ans << endl;
    return 0;

}
