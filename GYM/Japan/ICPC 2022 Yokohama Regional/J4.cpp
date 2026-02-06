#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m;
const double eps = 1e-10, pi = acos(-1.0);
inline int dcmp(LD x) {
    return (x > eps) - (x < -eps);
}
LD dis[N][N];
struct Point {
    LD x, y;
    int id;
    LD d;
    Point (double x = 0 , double y = 0) : x(x) , y(y) {}
    void input() {
        cin >> x >> y;
    }
    bool operator < (const Point& R) const {
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator * (const double& R) const {
        return Point(x * R, y * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R, y / R);
    }
    LD operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    LD operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    LD len() {
        return sqrt(*this % *this);
    }
    double angle() {
        return atan2(y, x);
    }
}p[N], poly[N];
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    LD t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    LD c1 = (a2 - a1) ^ (b1 - a1);
    LD c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2);
    }
    LD c3 = (b2 - b1) ^ (a1 - b1);
    LD c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point P, Point a1, Point a2) {
    LD len = (P - a1).len();
    if (dcmp(len) == 0) return true;
    a1 = a1 - P , a2 = a2 - P;
    return dcmp((a1 ^ a2) / len) == 0 && dcmp(a1 % a2) <= 0;
}
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2) {
    if (OnSegment(a1, b1, b2)) return true;
    if (OnSegment(a2, b1, b2)) return true;
    if (OnSegment(b1, a1, a2)) return true;
    if (OnSegment(b2, a1, a2)) return true;
    return SegmentProperIntersection(a1, a2, b1, b2);
}
int cmp(Point a, Point b) {
	if (a.id != b.id) return a.id < b.id;
	return a.d < b.d;
}
bool pointInPolygon(Point P , Point *p , int n) {
    for (int i = 0 ; i < n ; ++ i)
        if (OnSegment(P , p[i] , p[i + 1]))
            return 1;
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        Point a = p[i] , b = p[i + 1];
        if (a.y > b.y) swap(a , b);
        if (dcmp((a - P) ^ (b - P)) < 0 && dcmp(a.y - P.y) < 0 && dcmp(b.y - P.y) >= 0)
            res ^= 1;
    }
    return res;
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n + m) p[i].input();
	rep(i, 0, n) poly[i] = p[i + 1];
	poly[n] = p[1];
	repn(i, n + 1, n + m) {
		repn(j, 1, n) {
			Point x = p[j], y;
			if (j == n) y = p[1];
			else y = p[j + 1];
			if (!(p[i] == y) && OnSegment(p[i], x, y)) {
				p[i].id = j;
				p[i].d = (p[i] - x).len();
				break;
			}
		}
	}
	sort(p + n + 1, p + n + m + 1, cmp);
	repn(i, 1, n + m) repn(j, 1, n + m) {
		dis[i][j] = INF;
		Point x = p[i], y = p[j];
		vector<Point> v;
		v.pb(x), v.pb(y);
		repn(k, 1, n) {
			Point a = p[k], b;
			if (k == n) b = p[1];
			else b = p[k + 1];
			if (SegmentIntersection(x, y, a, b)) {
				Point z = GetLineIntersection(x, y - x, a, b - a);
				v.pb(z);
			}
		}
		sort(all(v));
		int flag = 0;
		rep(i, 1, SZ(v)) {
			if (v[i - 1] == v[i]) continue;
			Point c = (v[i - 1] + v[i]) / 2;
			if (!pointInPolygon(c, poly, n)) {
				flag = 1;
				break;
			}
		}
		if (!flag) dis[i][j] = (p[i] - p[j]).len();
	}
	repn(k, 1, n + m) repn(i, 1, n + m) repn(j, 1, n + m) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	double ans = 0;
	repn(i, n + 2, n + m) ans += dis[i - 1][i];
	ans += dis[n + m][n + 1];
	cout << fixed << setprecision(15) << ans << "\n";
	return 0;
}