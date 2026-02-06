#include <bits/stdc++.h>
using namespace std;

// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define per(i, a, b) for(int i = a; i > (b); --i)
// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

using i64 = long long;
using db = double;
constexpr int N = 210;
struct Point {
	i64 x, y;
	Point(i64 _x = 0, i64 _y = 0) : x(_x), y(_y) {}
	friend istream& operator >> (istream &in, Point &x) {
		in >> x.x >> x.y;
		return in;
	}
	friend ostream& operator << (ostream &out, Point x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
	friend Point operator - (Point x, Point y) {
		return Point(x.x - y.x, x.y - y.y);
	}
	friend bool operator < (Point x, Point y) {
		return x.y == y.y ? x.x < y.x : x.y < y.y;
	}
	friend bool operator == (Point x, Point y) {
		return x.y == y.y && x.x == y.x;
	}
	Point rot() {
		return Point(-y, x);
	}
	int sgn() {
		return y > 0 || y == 0 && x > 0;
	}
}a[N], b[N];
int n, m, ok[N][N], pos[N];
db G[N][N], dis[N][N];
i64 cross(Point x, Point y) {
	return x.x * y.y - x.y * y.x;
}
i64 dot(Point x, Point y) {
	return x.x * y.x + x.y * y.y;
}
int sgn(i64 x) {return (x > 0) - (x < 0);}
bool seg_cross(Point s1, Point t1, Point s2, Point t2) {
	int a = sgn(cross(t1 - s1, s2 - s1)), b = sgn(cross(t1 - s1, t2 - s1));
	int c = sgn(cross(t2 - s2, s1 - s2)), d = sgn(cross(t2 - s2, t1 - s2));
	return a * b == -1 && c * d == -1;
}
bool onseg(Point s, Point t, Point p) {
	return cross(t - s, p - s) == 0 && dot(t - s, p - s) > 0 && dot(s - t, p - t) > 0;
}
bool online(Point s, Point t, Point p) {
	return cross(t - s, p - s) == 0;
}
bool inpolygon(Point p) {
	int rev = 0;
	for(int i = 1; i <= n; i ++) {
		Point s = a[i], t = a[i % n + 1];
		i64 cur = cross(t - s, p - s);
		if(onseg(s, t, p) || s == p) return 1;
		if(s.y < p.y && p.y <= t.y && cur > 0) rev ^= 1;
		if(s.y >= p.y && p.y > t.y && cur < 0) rev ^= 1;
	}
	return rev;
}
vector<int> vec[N];
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	cout <<fixed <<setprecision(10);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i].x *= 2, a[i].y *= 2;
	}
	for(int i = 1; i <= m; i ++) {
		cin >> a[i + n];
		a[i + n].x *= 2, a[i + n].y *= 2;
		for(int j = 1; j <= n; j ++) {
			if(onseg(a[j], a[j % n + 1], a[i + n]) || a[i + n] == a[j]) {
				vec[j].emplace_back(i);
			}
		}
	}
	for(int i = 1; i <= n + m; i ++) {
		for(int j = 1; j <= n + m; j ++) {
			G[i][j] = 1e9;
			dis[i][j] = hypot(a[i].x - a[j].x >> 1, a[i].y - a[j].y >> 1);
		}
	}
    // rep(i,1,n+m+1) {
    //     rep(j,1,n+m+1) {
    //         debug() <<imie(i) <<imie(j) <<imie(dis[i][j]);;
    //     }
    // }        
	for(int i = 1; i <= n + m; i ++) {
		G[i][i] = 0;
		for(int j = i + 1; j <= n + m; j ++) {			
			ok[i][j] = 1;
			for(int k = 1; k <= n; k ++) {
				if(seg_cross(a[i], a[j], a[k], a[k % n + 1]) || onseg(a[i], a[j], a[k])) {
					ok[i][j] = 0;
				}
			}
			ok[i][j] &= inpolygon(Point(a[i].x + a[j].x >> 1, a[i].y + a[j].y >> 1));
			if(ok[i][j]) {
				G[i][j] = G[j][i] = dis[i][j]; 
			}
            // debug() <<imie(i) <<imie(j) <<imie(ok[i][j]);
		}
	}
	for(int k = 1; k <= n + m; k ++) {
		for(int i = 1; i <= n + m; i ++) {
			for(int j = 1; j <= n + m; j ++) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}

    // rep(i,1,n+m+1) {
    //     rep(j,1,n+m+1) {
    //         debug() <<imie(i) <<imie(j) <<imie(G[i][j]);;
    //     }
    // }
	
	vector<int> P;
	for(int i = 1; i <= n; i ++) {
		sort(vec[i].begin(), vec[i].end(), [&] (int x, int y) {return dis[x + n][i] < dis[y + n][i];});
		for(auto x : vec[i]) {
			P.emplace_back(x);
            // cout <<x <<"\n";
		}
	}
	db ans = 0;
	for(int i = 0; i < P.size(); i ++) {
		ans += G[P[i] + n][P[(i + 1) % P.size()] + n];
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}