#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

bool cycle;
vector <ll> graph[200010];
vector <ll> degree(200010) , visited(200010);
