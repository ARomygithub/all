#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
//typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef long long db;
const db EPS = 0;
  
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
  
inline int cmp(db a, db b){ return sign(a-b); }
  
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d}; }
 
	bool operator<(P p) const { 
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
 
	bool operator==(P o) const{
		return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
 
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }
	 
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y,x);}
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

bool isSS_strict(P p1, P p2, P q1, P q2){
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) < 0;
}

bool isMiddle(db a, db m, db b) {
	return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}
  
bool isMiddle(P a, P m, P b) {
	return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}

bool onSeg(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
}

bool onSeg_strict(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && sign((q-p1).dot(p1-p2)) * sign((q-p2).dot(p1-p2)) < 0;
}

const int N=410;
int n,m;
int ok[N][N];
P p2[N];
vector<P> p;
int contain(P q){ //2:inside,1:on_seg,0:outside
	int ret = 0; 
	rep(i,0,n){
		P u=p[i],v=p[(i+1)%n];
		if(onSeg(u,v,q)) return 1;
		if(cmp(u.y,v.y)<=0) swap(u,v);
		if(cmp(q.y,u.y) >0 || cmp(q.y,v.y) <= 0) continue;
		ret ^= crossOp(q,u,v) > 0;
	}
	return ret*2;
}

int checkok(int i,int j) {
	if (ok[i][j]!=-1) return ok[i][j];
	if (i==j) return ok[i][j]=0;
	if (j==(i+1)%n) return ok[i][j]=1;
	rep(k,0,n) if (isSS_strict(p[i],p[j],p[k],p[(k+1)%n])) {
		return ok[i][j]=0;
	}
	rep(k,0,n) if (onSeg_strict(p[i],p[j],p[k])) {
		return ok[i][j]=checkok(i,k)&checkok(k,j);
	}
	return ok[i][j]=contain((p[i]+p[j])/2)>=1;
}

double dis[410][410];
int main() {
	scanf("%d%d",&n,&m);
	p.resize(n);
	rep(i,0,n) {
		scanf("%lld%lld",&p[i].x,&p[i].y);
		p[i]=p[i]*2;
	}
	rep(i,0,m) {
		scanf("%lld%lld",&p2[i].x,&p2[i].y);
		p2[i]=p2[i]*2;
		bool sm=0;
		rep(j,0,SZ(p)) if (p2[i]==p[j]) sm=1;
		if (!sm) {
			bool fk=0;
			rep(j,0,SZ(p)) if (onSeg_strict(p[j],p[(j+1)%SZ(p)],p2[i])) {
				p.insert(p.begin()+j+1,p2[i]);
				fk=1;
				break;
			}
			assert(fk);
		}
	}
	//for (auto x:p) printf("-- %lld %lld\n",x.x,x.y);
	n=SZ(p);
	rep(i,0,n) rep(j,0,n) ok[i][j]=-1;
	rep(i,0,n) rep(j,0,n) ok[i][j]=checkok(i,j);
	rep(i,0,n) rep(j,0,n) {
		assert(ok[i][j]==ok[j][i]);
		if (ok[i][j]) {
			auto v=(p[i]-p[j]);
			dis[i][j]=dis[i][j]=sqrt(v.x*v.x+v.y*v.y);
			//printf("%d %d %.10f\n",i,j,dis[i][j]);
		} else dis[i][j]=1e10;
	}
	rep(k,0,n) rep(i,0,n) rep(j,0,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	VI id;
	rep(i,0,m) id.pb(find(all(p),p2[i])-p.begin());
	sort(all(id));
	double ans=0;
	rep(i,0,m) ans+=dis[id[i]][id[(i+1)%m]];
	printf("%.10f\n",ans/2);
}