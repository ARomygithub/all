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

const int mxn=1e5;
int na,nb;
set<int> s;

void rec(multiset<int>& ma, multiset<int>& mb, int hr, int sa, int sb) {
    if(hr==4) {
        s.insert(sa);
        return;
    }
    if(hr%2) {
        auto it = mb.begin();
        set<int> cand;
        while(it!=mb.end()) {
            cand.insert(*it);
            it++;
        }
        for(auto val: cand) {
            int cur = min(sb, val);
            mb.erase(mb.find(val));
            ma.insert(val);
            rec(ma,mb,hr+1,sa+cur,sb-cur);
            mb.insert(val);
            ma.erase(ma.find(val));
        }
    } else {
        auto it = ma.begin();
        set<int> cand;
        while(it!=ma.end()) {
            cand.insert(*it);
            it++;
        }
        for(auto val : cand) {
            int cur = min(sa, val);
            ma.erase(ma.find(val));
            mb.insert(val);
            rec(ma,mb,hr+1, sa-cur,sb+cur);
            ma.insert(val);
            mb.erase(mb.find(val));
        }
    }
}

void solve() {
    cin >>na >>nb;
    multiset<int> ma,mb;
    rep(i,0,na) {
        int x; cin >>x;
        ma.insert(x);
    }
    rep(i,0,nb) {
        int x; cin >>x;
        mb.insert(x);
    }
    rec(ma,mb,0,1000,1000);
    cout <<sz(s) <<"\n";
    // debug() <<imie(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}