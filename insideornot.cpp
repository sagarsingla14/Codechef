#include <iostream>
using namespace std;
#define ll long long int

#define INF 10000

struct Point {
	ll x;
	ll y;
};

bool onSegment(Point p, Point q, Point r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}

ll orientation(Point p, Point q, Point r) {
	ll val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
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

bool isInside(Point polygon[], ll n, Point p) {
	if (n < 3) return false;

	Point extreme = {INF, p.y};
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

ll main()
{
	Point polygon1[] = {{0, 0}, {6 , 0}, {6 , 6} , {0 , 6}};
	ll n = sizeof(polygon1) / sizeof(polygon1[0]);
	Point p = {-5 , -5};
	isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

	return 0;
}
