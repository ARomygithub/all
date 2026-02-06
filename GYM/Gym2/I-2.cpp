#include <bits/stdc++.h>
using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}

#define fast_function \
  __attribute__((__optimize__("O3, unroll-loops"))) \
  __attribute__((__target__("avx, avx2, sse, sse2, sse3, sse4, popcnt, fma")))
/** END OF DESPERATE OPTIMIZATION **/

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, double t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(PT a, double t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
double SQ(double x) { return x * x; }
double rad_to_deg(double r) { return (r * 180.0 / PI); }
double deg_to_rad(double d) { return (d * PI / 180.0); }
double get_angle(PT a, PT b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double)-1.0, min((double)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c, PT p) { // does point p lie in angle <bac
    assert(orientation(a, b, c) != 0);
    if (orientation(a, c, b) < 0) swap(b, c);
    return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) {
    return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0);
}
void polar_sort(vector<PT> &v) { // sort points in counterclockwise
    sort(v.begin(), v.end(), [](PT a,PT b) {
        return make_tuple(half(a), 0.0, a.norm2()) < make_tuple(half(b), cross(a, b), b.norm2());
    });
}
void polar_sort(vector<PT> &v, PT o) { // sort points in counterclockwise with respect to point o
    sort(v.begin(), v.end(), [&](PT a,PT b) {
        return make_tuple(half(a - o), 0.0, (a - o).norm2()) < make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
    });
}
// -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
int is_point_in_triangle(PT a, PT b, PT c, PT p) {
    if (sign(cross(b - a,c - a)) < 0) swap(b, c);
    int c1 = sign(cross(b - a,p - a));
    int c2 = sign(cross(c - b,p - b));
    int c3 = sign(cross(a - c,p - c));
    if (c1<0 || c2<0 || c3 < 0) return 1;
    if (c1 + c2 + c3 != 3) return 0;
    return -1;
}

const int N = 300;


const int mxn=300;
int n;
PT pt[mxn];
int ft[mxn+1][mxn+1];

void upd(int i2, int j2, int x) {
    for(int i=i2;i<=n;i+=i&-i) {
        for(int j=j2;j<=n;j+=j&-j) {
            ft[i][j] +=x;
        }
    }
}

int qry(int i2, int j2) {
    int r=0;
    for(int i=i2;i;i -=i&-i) {
        for(int j=j2;j;j-=j&-j) {
            r +=ft[i][j];
        }
    }
    return r;
}

#define pdd pair<double,double>
#define pddi pair<pdd,int>
#define pdi pair<double,int>

void solve() {
    in(n);
    for(int i=0;i<n;i++) {
        // cin >>pt[i].x >>pt[i].y;
        int tempx, tempy;
        in(tempx);
        in(tempy);
        pt[i].x = tempx;
        pt[i].y = tempy;
    }
    sort(pt,pt+n);
    ll ans=0;
    for(int i = 0; i<n;i++) {
        for(int k=i+2;k<n;k++) {
            vector<vector<pdd>> v(2);
            vector<vector<pdi>> vl(2);
            vector<vector<pdi>> vr(2);
            for(int j=i+1;j<k;j++) {
                if(sign(cross(pt[j]-pt[i],pt[k]-pt[i]))>0) {
                    double angle_l = get_angle(pt[j]-pt[i],pt[k]-pt[i]);
                    double angle_r = get_angle(pt[i]-pt[k],pt[j]-pt[k]);
                    v[0].push_back({angle_l,angle_r});
                    vl[0].push_back({angle_l,j});
                    vr[0].push_back({angle_r,j});
                } else {
                    double angle_l = get_angle(pt[k]-pt[i],pt[j]-pt[i]);
                    double angle_r = get_angle(pt[j]-pt[k],pt[i]-pt[k]);
                    v[1].push_back({angle_l,angle_r});
                    vl[1].push_back({angle_l,j});
                    vr[1].push_back({angle_r,j});
                }
            }
            for(int j=0;j<2;j++) {
                // memset(bit.M, 0, sizeof bit.M);
                // memset(bit.A, 0, sizeof bit.A);
                sort(vl[j].begin(),vl[j].end());
                sort(vr[j].begin(),vr[j].end());
                map<double,int> mpl, mpr;
                for(int jj=0;jj<sz(vl[j]);jj++) {
                    mpl[vl[j][jj].fi] = jj+1;
                }
                for(int jj=0;jj<sz(vr[j]);jj++) {
                    mpr[vr[j][jj].fi] = jj+1;
                }
                for(auto [angle_l,angle_r]: v[j]) {
                    int lll = mpl[angle_l];
                    int rr = mpr[angle_r];
                    // bit.upd(lll,rr,lll,rr,1ll);
                    upd(lll,rr,1);
                }
                for(auto [angle_l,angle_r]: v[j]) {
                    int lll = mpl[angle_l];
                    int rr = mpr[angle_r];
                    // ll temp = bit.query(1,1,lll,rr);
                    ll temp = qry(lll,rr);
                    temp--;
                    ans += temp*(temp-1)*(temp-2)/6;
                }
                for(auto [angle_l,angle_r]: v[j]) {
                    int lll = mpl[angle_l];
                    int rr = mpr[angle_r];
                    // bit.upd(lll,rr,lll,rr,-1ll);
                    upd(lll,rr,-1);
                }                
            }
        }
    }
    out(ans, '\n');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int s;
    // cin >>s;
    solve();
}