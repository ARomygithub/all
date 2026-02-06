#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=40;
int r1,b1,r2,b2;
using pipi = pair<pii,pii>;
using pipii = pair<pipi,int>;
map<pipii,double> dp;

double getdp(int ri1, int bi1, int ri2, int bi2, int isguessr) {
    pipi st = {{ri1,bi1},{ri2,bi2}};
    if(dp.count({st,isguessr})) return dp[{st,isguessr}];
    if(ri1==0 || bi1==0) {
        dp[{st,isguessr}] = 0;
        return dp[{st,isguessr}];
    }
    if(ri2==0 || bi2==0) {
        dp[{st,isguessr}] = 1;
        return dp[{st,isguessr}];
    }
    if(isguessr) {
        double tmp = max(getdp(ri1,bi1,ri2-1,bi2,1-isguessr)+getdp(ri1-1,bi1,ri2,bi2,1-isguessr), getdp(ri1,bi1,ri2,bi2-1,1-isguessr)+getdp(ri1,bi1-1,ri2,bi2,1-isguessr))/2;
        dp[{st,isguessr}] = tmp;
        return dp[{st,isguessr}];
    } else {
        dp[{st,isguessr}] = 1-getdp(ri2,bi2,ri1,bi1,1-isguessr);
        return dp[{st,isguessr}];
    }
}

void solve() {
    cin >>r1 >>b1 >>r2 >>b2;
    cout <<fixed <<setprecision(8) <<getdp(r1,b1,r2,b2,0) <<"\n"; 
    // debug() <<imie(dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}