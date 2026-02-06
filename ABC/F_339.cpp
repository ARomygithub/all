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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

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

const int mxn=1e3;
int n;
string a[mxn];

H getHash(string ai) {
    H ha(0);
    H p10(10);
    rep(i,0,sz(ai)) {
        H hi(ai[i]-'0');
        ha = ha * p10 + hi;
    }
    return ha;
}

void solve() {
    cin >>n;
    vector<H> v;
    rep(i,0,n) {
        cin >>a[i];
        v.push_back(getHash(a[i]));
    }
    map<ull, int> mp;
    rep(i,0,n) {
        mp[(ull) v[i]]++;
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            H temp1 = v[i]*v[j];
            ans += mp[(ull) temp1];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}