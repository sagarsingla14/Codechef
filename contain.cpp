// doIntersect taken from geeksforgeeks

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

struct pt{
    ll x, y;
};


ll n , q;
vector <pt> v;
vector <vector <pt> > hull;

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (ll i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    map <pair <long long , long long> , ll> mp;
    for(auto i : a) {
        mp[{i.x , i.y}] = 1;
    }

    a.clear();
    for (ll i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (ll i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

    for(auto i : a) {
        mp[{i.x , i.y}] = 0;
    }

    v.clear();

    for(auto i : mp) {
        if(i.second == 1) {
            pt *node = new pt();
            node -> x = (i.first).first;
            node -> y = (i.first).second;
            v.push_back(*node);
        }
    }
    hull.push_back(a);
}

bool onSegment(pt p, pt q, pt r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}

ll orientation(pt p, pt q, pt r) {
	ll val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
}

bool doIntersect(pt p1, pt q1, pt p2, pt q2) {
	ll o1 = orientation(p1, q1, p2);
	ll o2 = orientation(p1, q1, q2);
	ll o3 = orientation(p2, q2, p1);
	ll o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}

bool isInside(vector <pt> polygon , ll n, pt p) {
	if (n < 3) return false;

	pt extreme = {10000000000 , p.y};
	ll count = 0, i = 0;
	do {
		ll next = (i + 1) % n;
		if (doIntersect(polygon[i], polygon[next], p, extreme)) {
			ll flag = 0;
			if (orientation(polygon[i], p, polygon[next]) == 0) {
				if(onSegment(polygon[i], p, polygon[next])) {
					return false;
				}
				else {
					flag = 1;
				}
			}

			if(!flag) {
				count++;
			}
		}
		i = next;
	} while (i != 0);
	return count & 1;
}


int main() {
    ll t;
    cin >> t;
    while(t--) {
        v.clear();
        hull.clear();
        cin >> n >> q;
        for(ll i = 0 ; i < n ; i++) {
            long long a , b;
            cin >> a >> b;
            pt *node = new pt();
            node -> x = a;
            node -> y = b;
            v.push_back(*node);
        }

        while(v.size() >= 1) {
            vector <pt> a = v;
            convex_hull(a);
        }

        while(q--) {
            ll a , b;
            cin >> a >> b;
            pt *node = new pt();
            node -> x = a;
            node -> y = b;
            ll ans = 0;

            for(ll i = 0 ; i < hull.size() ; i++) {
                vector <pt> a = hull[i];

                if(isInside(a , a.size(), *node)) {
                    ans ++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
