#include <bits/stdc++.h>
#define ll long long int
using namespace std;

float dist(int x1, int y1, int x2, int y2){
      return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    int cnt = 0;
    map<int, vector<pair<int, int>>> map1, map2;
    vector<vector<int>> mat(m, vector<int>(n));
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                // count += map1[i+j]++;
                // count += map2[i-j]++;
                map1[i + j].push_back(make_pair(i, j));
                map2[i - j].push_back(make_pair(i, j));

                for (auto p : map1[i+j])
                {
                    if (dist(i, j, p.first, p.second) <= k)
                    {
                        count++;
                    }
                }

                for (auto p : map2[i-j])
                {
                    if (dist(i, j, p.first, p.second) <= k)
                    {
                        count++;
                    }
                }
            }
        }
    }

    for(ll i = 0  ; i < 100 ; i++) {
        ll x = 100;
    }


    cout << count;

    return 0;
}
