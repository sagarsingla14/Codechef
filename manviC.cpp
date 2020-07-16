#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
#define F first
#define S second
#define ppi pair<int, int>

void solve()
{
    int n;
    cin >> n;

    vector<ppi> act;
    for (int i = 0; i < n; i++)
    {
        int st, en;
        cin >> st >> en;
        act.push_back(MP(st, en));
    }

    vector<int> cam, jam;

    for (int i = 0; i < act.size(); i++)
    {

        int ast = act[i].F;
        int aend = act[i].S;
        bool overlap = false;

        //cam me overlaaping check karo , yahi se baat ban jaati hai to badiya continue
        for (auto c : cam)
        {
            int bst = act[c].F;
            int bend = act[c].S;


            if ((ast <= bst && aend > bst) || (ast < bend && ast >= bst))
            {
                overlap = true;
                break;
            }
        }

        if (!overlap)
        {
            cam.push_back(i);
            continue;
        }

        overlap = false;

        //jam me overlaaping check karo , yahi se baat ban jaati hai to badiya continue
        for (auto j : jam)
        {
            int bst = act[j].F;
            int bend = act[j].S;

            if ((ast <= bst && aend > bst) || (ast < bend && ast >= bst))
            {
                overlap = true;
                break;
            }

        }

        if (!overlap)
        {
            jam.push_back(i);
            continue;
        }

        //cout Impsbl
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<char> ans(n);

    for (auto i : cam)
    {
        ans[i] = 'C';
    }

    for (auto i : jam)
    {
        ans[i] = 'J';
    }

    for (auto c : ans)
    {
        cout << c;
    }

    cout << endl;
}

int main()
{
    int t, i = 1;
    cin >> t;

    while (t--)
    {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
}
