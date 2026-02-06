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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};


const int mxn=1e6;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    string bef="";
    string af="";
    vector<int> ct(n,0);
    map<char,int> mp;
    mp['A'] = 1;
    mp['B'] = -1;
    int a0 = mp[s[0]];
    vector<H> pw(n+1,0);
    pw[0] = 1;
    rep(i,1,n+1) {
        pw[i] = pw[i-1]*C;
    }
    rep(i,1,n) {
        int si = mp[s[i]];
        ct[i] = ct[i-1]+si;
        if(ct[i]>0) {
            bef +='A';
        } else if(ct[i]<0) {
            bef +='B';
        } else {
            bef +='C';
        }
        if(ct[i]+a0>0) {
            af +='A';
        } else if(ct[i]+a0<0) {
            af +='B';
        } else {
            af +='C';
        }
    }
    HashInterval hib(bef), hif(af);
    map<ull,int> ctans;
    rep(i,0,n) {
        char c0;
        if(ct[i]+a0>0) {
            c0 = 'A';
        } else if(ct[i]+a0<0) {
            c0 = 'B';
        } else {
            c0 = 'C';
        }
        H now = hif.hashInterval(i,n-1);
        H hc0 = c0;
        H temp = hib.hashInterval(0,i);
        now = now + hc0*pw[n-1-i] + temp*pw[n-i];
        ctans[now.get()]++;
    }
    cout <<sz(ctans) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}