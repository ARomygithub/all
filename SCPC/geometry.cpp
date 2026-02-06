template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

P linearTransformation(const P& p0, const P& p1,
		const P& q0, const P& q1, const P& r) {
	P dp = p1-p0, dq = q1-q0, num(dp.cross(dq), dp.dot(dq));
	return q0 + P((r-p0).cross(num), (r-p0).dot(num))/dp.dist2();
}

struct Angle {
	int x, y;
	int t;
	Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (a.t180() < r) r.t--;
	return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = sz(p);
	rep(i,0,n) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		//or: if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

typedef Point<double> P;
P polygonCenter(const vector<P>& v) {
	P res(0, 0); double A = 0;
	for (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {
		res = res + (v[i] + v[j]) * v[j].cross(v[i]);
		A += v[j].cross(v[i]);
	}
	return res / A / 3;
}

vector<P> polygonCut(const vector<P>& poly, P s, P e) {
	vector<P> res;
	rep(i,0,sz(poly)) {
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0))
			res.push_back(lineInter(s, e, cur, prev).second);
		if (side)
			res.push_back(cur);
	}
	return res;
}

vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

array<P, 2> hullDiameter(vector<P> S) {
	int n = sz(S), j = n < 2 ? 0 : 1;
	pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
	rep(i,0,j)
		for (;; j = (j + 1) % n) {
			res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});
			if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)
				break;
		}
	return res.second;
}

bool inHull(const vector<P>& l, P p, bool strict = true) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(l[a].cross(l[b], p)) < r;
}

#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P> int extrVertex(vector<P>& poly, P dir) {
	int n = sz(poly), lo = 0, hi = n;
	if (extr(0)) return 0;
	while (lo + 1 < hi) {
		int m = (lo + hi) / 2;
		if (extr(m)) return m;
		int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
		(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
	}
	return lo;
}

#define cmpL(i) sgn(a.cross(poly[i], b))
template <class P>
array<int, 2> lineHull(P a, P b, vector<P>& poly) {
	int endA = extrVertex(poly, (a - b).perp());
	int endB = extrVertex(poly, (b - a).perp());
	if (cmpL(endA) < 0 || cmpL(endB) > 0)
		return {-1, -1};
	array<int, 2> res;
	rep(i,0,2) {
		int lo = endB, hi = endA, n = sz(poly);
		while ((lo + 1) % n != hi) {
			int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;
			(cmpL(m) == cmpL(endB) ? lo : hi) = m;
		}
		res[i] = (lo + !cmpL(hi)) % n;
		swap(endA, endB);
	}
	if (res[0] == res[1]) return {res[0], -1};
	if (!cmpL(res[0]) && !cmpL(res[1]))
		switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {
			case 0: return {res[0], res[0]};
			case 2: return {res[1], res[1]};
		}
	return res;
}

pair<P, P> closest(vector<P> v) {
	assert(sz(v) > 1);
	set<P> S;
	sort(all(v), [](P a, P b) { return a.y < b.y; });
	pair<ll, pair<P, P>> ret{LLONG_MAX, {P(), P()}};
	int j = 0;
	for (P p : v) {
		P d{1 + (ll)sqrt(ret.first), 0};
		while (v[j].y <= p.y - d.x) S.erase(v[j++]);
		auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
		for (; lo != hi; ++lo)
			ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
		S.insert(p);
	}
	return ret.second;
}