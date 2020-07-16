#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009

bool isAlpha(char test)
{
    if ((test >= 'a' && test <= 'z') || (test >= 'A' && test <= 'Z'))
        return true;

    return false;
}

bool isNum(char testc)
{

    int test = testc - '0';
    if ((test >= 1 && test <= 9))
        return true;

    return false;
}

string wildcard(string str)
{
    int i;
    string pattern, expr;
    for (i = 0; i < str.size() && str[i] != ' '; i++)
    {
        pattern.push_back(str[i]);
    }
    i++;

    for (; i < str.size(); i++)
    {
        expr.push_back(str[i]);
    }

    int p = 0, e = 0;

    while (p < pattern.size() && e < expr.size())
    {

        if (pattern[p] == '+')
        {
            if (!(isAlpha(expr[e])))
            {
                // cout << "1 ";
                return "false";
            }
            p++, e++;
        }
        else if (pattern[p] == '$')
        {
            if (!(isNum(expr[e])))
            {
                  // cout << "2 ";
                return "false";
            }
            p++, e++;
        }
        else if (pattern[p] == '*')
        {
            if (p + 1 < pattern.size() && pattern[p + 1] != '{')
            {
                for (int cnt = 1; cnt < 2; cnt++)
                {
                    if (expr[e + cnt] != expr[e + cnt - 1])
                    {
                        return "false";
                    }
                }
                e += 3;
                p++;
            }
            else if (p + 1 < pattern.size() && pattern[p + 1] == '{')
            {
                p+=2;

                int N = pattern[p] - '0';

               for (int cnt = 1; cnt < N; cnt++)
                {
                    if (expr[e + cnt] != expr[e + cnt - 1])
                    {
                          cout << "4 ";
                        return "false";
                    }
                }
                e += N;
                p+=2;
            }
        }
    }

    return "true";
}
int main()
{
    string str;
    getline(cin,str);
    cout << wildcard(str);
}
