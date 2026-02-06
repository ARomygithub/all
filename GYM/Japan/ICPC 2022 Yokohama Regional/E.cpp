#include <bits/stdc++.h>
using namespace std;

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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod= 998244353;
int n;
string s;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return (a + b)%mod; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    cin >>s;
    n = s.length();
    vector<pii> v(n+1);
    vector<piii> v1(n+1),v2(n+1),v3(n+1);
    v[0] = {0,0};
    v1[0] = {{0,0},0};
    v2[0] = {{0,0},0};
    v3[0] = {{0,0},0};
    rep(i,0,n) {
        v[i+1] = v[i];
        if(s[i]=='C') {
            v[i+1].se++;
        } else if(s[i]=='I') {
            v[i+1].fi++;
        } else {
            v[i+1].fi--;
            v[i+1].se--;
        }
        v1[i+1] = {v[i+1],i+1};
        v2[i+1] = {{v[i+1].se,v[i+1].fi},i+1};
        v3[i+1] = {{v[i+1].fi-v[i+1].se,v[i+1].fi},i+1};
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    map<int,int> mp1,mp2,mp3;
    vector<pii> pos1(n+1),pos2(n+1),pos3(n+1);
    int ctc=-1,cti=-1,ctp=-1;
    rep(i,0,n+1) {
        if(i>0 && v1[i].fi == v1[i-1].fi) {
            pos1[v1[i].se] = pos1[v1[i-1].se];
        } else {
            if(i==0 || v1[i].fi.fi!=v1[i-1].fi.fi) {
                ctc++;
            }
            pos1[v1[i].se] = {ctc, mp1[v1[i].fi.fi]++};
        }
        if(i>0 && v2[i].fi == v2[i-1].fi) {
            pos2[v2[i].se] = pos2[v2[i-1].se];
        } else {
            if(i==0 || v2[i].fi.fi!=v2[i-1].fi.fi) {
                cti++;
            }
            pos2[v2[i].se] = {cti, mp2[v2[i].fi.fi]++};
        }
        if(i>0 && v3[i].fi == v3[i-1].fi) {
            pos3[v3[i].se] = pos3[v3[i-1].se];
        } else {
            if(i==0 || v3[i].fi.fi!=v3[i-1].fi.fi) {
                ctp++;
            }
            pos3[v3[i].se] = {ctp, mp3[v3[i].fi.fi]++};
        }
    }
    vector<Tree> t1,t2,t3;
    for(auto [k,val]: mp1) {
        t1.push_back(Tree(val));
    }
    for(auto [k,val]: mp2) {
        t2.push_back(Tree(val));
    }
    for(auto [k,val]: mp3) {
        t3.push_back(Tree(val));
    }
    vector<ll> ans(n+1,0);
    ans[0] = 1;
    t1[pos1[0].fi].update(pos1[0].se, ans[0]);
    t2[pos2[0].fi].update(pos2[0].se, ans[0]);
    t3[pos3[0].fi].update(pos3[0].se, ans[0]);
    // debug() <<imie(v);
    // debug() <<imie(pos1);
    // debug() <<imie(pos2);
    // debug() <<imie(pos3);
    rep(i,1,n+1) {
        // cout <<i <<"\n";
        ll now = 0;
        ll ansi = 0;
        ansi = (ansi+ t1[pos1[i].fi].query(0,pos1[i].se))%mod;
        // cout <<ansi <<"\n";
        ansi = (ansi + t2[pos2[i].fi].query(0,pos2[i].se))%mod;
        // cout <<ansi <<"\n";
        ansi = (ansi + t3[pos3[i].fi].query(pos3[i].se+1,t3[pos3[i].fi].n))%mod;
        ans[i] = ansi;
        // cout <<ansi <<"\n";
        now = (now + t1[pos1[i].fi].query(pos1[i].se,pos1[i].se+1))%mod;
        now = (now + ansi)%mod;
        // debug() <<imie(now);
        t1[pos1[i].fi].update(pos1[i].se, now);
        t2[pos2[i].fi].update(pos2[i].se, now);
        t3[pos3[i].fi].update(pos3[i].se, now);
    } 
    cout <<ans[n] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}