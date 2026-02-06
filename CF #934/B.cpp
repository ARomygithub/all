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
static int C; // initialized below

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

const int mxn=2e5;
int n,q,t;
string s;

void solve() {
    cin >>n >>q;
    cin >>s;
    HashInterval hs(s);
    string sr = s;
    reverse(sr.begin(),sr.end());
    // cout <<sr <<"\n";
    HashInterval hsr(sr);
    vector<pii> v1,v2;
    for(int i=0;i<n;) {
        int l = i;
        while(i+1<n && s[i+1]==s[l]) {
            i++;
        }
        v1.push_back({l,i});
        i++;
    }
    for(int i=0;i+2<n;) {
        if(s[i]==s[i+2] && s[i]!=s[i+1]) {
            int l = i;
            i = i+2;
            while(i+1<n && ((s[i+1]==s[l+ (i+1-l)%2]))) {
                i++;
            }
            v2.push_back({l,i});
        } else {
            i++;
        }
    }
    while(q--) {
        int l, r; cin >>l >>r; l--,r--;
        pii lrn = {l,n+5};
        auto ret = --upper_bound(v1.begin(),v1.end(),lrn);
        assert(ret->fi <=l);
        assert(ret->fi >=0 && ret->fi <n);
        assert(ret->se>=0 && ret->se<n);        
        if(ret->se >=r) {
            cout <<"0\n";
            continue;
        }
        if(r-l+1>=3 && sz(v2) && v2[0].fi<=l) {
            ret = --upper_bound(v2.begin(),v2.end(),lrn);
            // cout <<(ret->fi) <<" " <<(ret->se) <<"\n";
            assert(ret->fi <=l);
            assert(ret->fi >=0 && ret->fi <n);
            assert(ret->se>=0 && ret->se<n);
            if(ret->se >=r) {
                ll len = r-l+1;
                ll hlen = len/2;
                ll ans = 1ll*hlen*(hlen+1);
                cout <<ans <<"\n";
                continue;
            }
        }
        ll len = r-l+1;
        ll ans = 1ll*len*(len+1)/2 - 1;
        if((ull) hs.hashInterval(l,r+1) == (ull) hsr.hashInterval(n-1-r,n-1-r+len)) {
            ans -=len;
        }
        cout <<ans <<"\n";
    }
}

#include<sys/time.h>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    timeval tp;
	gettimeofday(&tp, 0);
    ll mod = 1e9+7;
	C = ((int)tp.tv_usec)%(mod); // (less than modulo)
    cin >>t;
    while(t--) {
        solve();
    }
}