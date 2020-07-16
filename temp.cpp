#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , m , k;
vector <ll> graph[200001];
ll degree[200001] = {0};
set <pair <ll , ll> > s;
vector <pair <ll , ll> > edges;
vector <ll> ans;
ll stop = 0;

void fillSet() {
    for(ll i = 1 ; i <= n ; i++) {
        s.insert({degree[i] , i});
    }
}

void input() {
    cin >> n >> m >> k;
    for(ll i = 0 ; i < m ; i ++) {
        ll u , v;
        cin >> u >> v;
        degree[u] ++;
        degree[v] ++;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u , v});
    }
}

vector <ll> fillAdjacent(ll node) {
    vector <ll> v;
    for(auto i : graph[node]) {
        v.push_back(i);
    }
    return v;
}

void fixSet() {
    if(s.size() == 0) {
        stop = 1;
    }
    while((s.begin()) -> first < k && !s.empty()) {
        auto itr = s.begin();
        ll secondValue = itr -> second;
        if(s.size() == 0) {
            stop = 1;
        }
        s.erase(itr);

        vector <ll> v = fillAdjacent(secondValue);
        for(auto i : v) {
            ll curDegree = degree[i];
            auto pos = s.find({curDegree , i});
            if(s.find({curDegree , i}) != s.end()) {

                cout << 1 << endl;
                s.erase(pos);
                if(curDegree - 1 > 0) {
                    s.insert({curDegree - 1 , i});
                    degree[i] --;
                }
                if(s.size() == 0 || stop) {
                    stop = 1;
                    break;
                }
            }
        }

        degree[secondValue] = 0;
        if(s.size() == 0 || stop) {
            stop = 1;
            break;
        }
    }
}

void calcAnswer() {
    for(ll i = m - 1 ; i >= 0 ; i --) {
        if(stop) {
            ans.push_back(0);
        }
        else{
            ans.push_back(s.size());

            ll u = edges[i].first;
            ll v = edges[i].second;

            ll node1 = u;
            ll node2 = v;
            ll degreeNode1 = degree[u];
            ll degreeNode2 = degree[v];

            auto itr = s.find({degreeNode1 , node1});
            s.erase(itr);
            if(degreeNode1 - 1 > 0) {
                s.insert({degreeNode1 - 1 , node1});
            }

            itr = s.find({degreeNode2 , node2});
            s.erase(itr);
            if(degreeNode2 - 1 > 0) {
                s.insert({degreeNode2 - 1 , node2});
            }

            degree[node1] --;
            degree[node2] --;
            fixSet();
        }
    }
    reverse(ans.begin() , ans.end());
}

void printAswer() {
    for(auto i : ans) {
        cout << i << endl;
    }
}

int main() {

    input();
    fillSet();
    fixSet();
    calcAnswer();
    printAswer();
    return 0;
}
