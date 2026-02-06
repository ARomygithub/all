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

const int mxn=120;
int n,m,p;

void tes() {
    vi v(n*m-1);
    iota(all(v),0);
    ll ans = 0;
    do {
        vi inc, dc;
        rep(i,0,sz(v)) {
            auto it1 = lower_bound(all(inc),v[i]);
            if(it1==inc.end()) {
                inc.push_back(v[i]);
            } else {
                *it1 = v[i];
            }
            auto it2 = lower_bound(all(dc),-v[i]);
            if(it2==dc.end()) {
                dc.push_back(-v[i]);
            } else {
                *it2 = -v[i];
            }
        }
        if(sz(inc)==n && sz(dc)==m) {
            if(inc.back() > dc.back()*-1) {
                // assert(inc.back()==n*m-2);
                // debug() <<imie(v);
                // debug() <<imie(inc) imie(dc);
                ans++;
            }
        }
    } while(next_permutation(all(v)));
    cout <<ans <<endl;
}

void solve() {
    cin >>n >>m >>p;
    tes();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}