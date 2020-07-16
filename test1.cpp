#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isAlpha(char test) {
    if ((test >= 'a' && test <= 'z') || (test >= 'A' && test <= 'Z')) {
        return true;
    }
    else{
        return false;
    }
}

bool isNum(char testc)
{

    int test = testc - '0';
    if ((test >= 1 && test <= 9)) {
        return true;
    }

    else{
        return false;
    }
}

string wildcard(string str) {
    string pattern = "";
    string expr = "";
    ll i = 0;
    for (i = 0; i < str.size() && str[i] != ' '; i++) {
        pattern += str[i];
    }

    for (i = i + 1 ; i < str.size(); i++) {
        expr += str[i];
    }

    ll p = 0, e = 0;

    while (p < pattern.size() && e < expr.size()) {

        if (pattern[p] == '+') {
            if (!(isAlpha(expr[e]))) {
                return "false";
            }
            p++, e++;
        }
        else if (pattern[p] == '$')
        {
            if (!(isNum(expr[e])))
            {
                return "false";
            }
            p++, e++;
        }
        else if (pattern[p] == '*')
        {
            if (p + 1 < pattern.size() && pattern[p + 1] != '{')
            {
                if((expr[e] == expr[e + 1] && expr[e + 1] == expr[e + 2] && e + 2 < expr.size()) == false ) {
                    return "false";
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
                    if (expr[e + cnt] != expr[e + cnt - 1] ) {
                        return "false";
                    }
                    if(e + cnt >= expr.size()) {
                        return "false";
                    }
                }
                e += N;
                p += 2;
            }
        }
    }

    if(e == expr.size() && p == pattern.size()) {
        return "true";
    }
    else{
        return "false";
    }
}



int main() {
    string str;
    getline(cin,str);
    cout << wildcard(str);
}
