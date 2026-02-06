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

const int mxn=2e5;
int n,q;
int a[mxn],b[mxn];

typedef uint64_t ull;
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

const H C = 998244353;

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<H> pw(n+1);
    pw[0] = 1;
    rep(i,1,n+1) {
        pw[i] = pw[i-1]*C;
    }
    vector<H> prefa(n+1), prefb(n+1);
    rep(i,1,n+1) {
        prefa[i] = prefa[i-1] + pw[a[i-1]];
    }
    rep(i,1,n+1) {
        prefb[i] = prefb[i-1] + pw[b[i-1]];
    }
    while(q--) {
        int l1,r1,l2,r2; cin >>l1 >>r1 >>l2 >>r2;
        if(r1-l1==r2-l2 && (ull)(prefa[r1]-prefa[l1-1]) == (ull)(prefb[r2]-prefb[l2-1])) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}