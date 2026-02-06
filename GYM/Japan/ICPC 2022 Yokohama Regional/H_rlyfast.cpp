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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll X,L,R;
ll ans=0;
ll dsqrt(ll x) {
	ll y=sqrt(x)+0.1;
	while (y*y>x) --y;
	return y;
}
ll calc(ll X,ll R) {
	ll ans=0;
	auto num=[&](ll l,ll r) {
		return l<=r?r-l+1:0ll;
	};
	auto cd=[&](ll a,ll b) {
		return (a+b-1)/b;
	};
	for (ll a=1;a*(a+1)*(a+2)*(a+3)<=X;a++) {
		for (ll b=a+1;a*b*(b+1)*(b+2)<=X;b++) {
			ll x=X/a/b;
			ll lc=b+1,rc=(dsqrt(4*x+1)-1)/2;
			if (a+b<=R) ans+=rc-lc+1;
			ans+=num(lc,min(R-a,rc));
			ans+=num(lc,min(R-b,rc));
			if (a+rc+1<=R) {
				ans+=num(max(lc,x/(R-a+1)+1),rc);
			}
			if (b+rc+1<=R) {
				ans+=num(max(lc,x/(R-b+1)+1),rc);
			}
			if (rc+x/rc<=R) {
				if (lc+x/lc<=R)	ans+=rc-lc+1;
				else {
					ll l=lc,r=rc;
					while (l+1<r) {
						ll md=(l+r)/2;
						if (md+x/md<=R) r=md; else l=md;
					}
					ans+=rc-r+1;
				}
			}
		}
	}
	//printf("!! %lld\n",ans*4);
	return ans*4;
}

/*ll calc2(ll X,ll R) {
	ll ans=0;
	for (ll a=1;a*(a+1)*(a+2)*(a+3)<=X;a++) {
		for (ll b=a+1;a*b*(b+1)*(b+2)<=X;b++) {
			for (ll c=b+1;a*b*c*(c+1)<=X;c++) {
				ll d=X/a/b/c;
				if (a+b<=R) ans++;
				if (a+c<=R) ans++;
				if (a+d<=R) ans++;
				if (b+c<=R) ans++;
				if (b+d<=R) ans++;
				if (c+d<=R) ans++;
			}
		}
	}
	return ans*4;
}*/
int main() {
	scanf("%lld%lld%lld",&X,&L,&R);
	ans=calc(X,R-1)-calc(X,L-1);
	/*assert(calc(100000000000ll,1)==calc2(100000000000ll,1));
	assert(calc(100000000000ll,12)==calc2(100000000000ll,12));
	assert(calc(100000000000ll,123)==calc2(100000000000ll,123));
	assert(calc(100000000000ll,1234)==calc2(100000000000ll,1234));
	assert(calc(100000000000ll,12345)==calc2(100000000000ll,12345));
	assert(calc(100000000000ll,123456)==calc2(100000000000ll,123456));
	assert(calc(100000000000ll,1234567)==calc2(100000000000ll,1234567));
	assert(calc(100000000000ll,12345678)==calc2(100000000000ll,12345678));
	assert(calc(100000000000ll,123456789)==calc2(100000000000ll,123456789));
	assert(calc(100000000000ll,1234567890)==calc2(100000000000ll,1234567890));*/
	printf("%lld\n",ans%998244353);
}