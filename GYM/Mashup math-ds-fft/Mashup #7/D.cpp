#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5;
int n,m,t;
ll c[mxn+1];

typedef uint64_t ull;
// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

void solve() {
    cin >>n >>m;
    rep(i,1,n+1) {
        cin >>c[i];
    }
    vector vr(n+1, set<int>());
    rep(i,0,m) {
        int u,v; cin >>u >>v; 
        vr[v].insert(u);
    }
    ll ans = 0;
    map<ull,ll> mp;
    rep(i,1,n+1) {
        if(sz(vr[i])) {
            H cur = 0;
            for(auto le : vr[i]) {
                cur = cur*C + H(le);
            }
            mp[(ull)cur] += c[i];
        }
    }
    for(auto [hs, val]: mp) {
        ans = __gcd(ans, val);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}