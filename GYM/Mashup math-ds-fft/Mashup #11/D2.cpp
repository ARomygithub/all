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

const int mxn=2e5;
int n,q;

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (min_self(s[pos += n], val); pos /= 2;)
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
    cin >>n >>q;
    set<int> s;
    rep(i,0,n) {
        s.insert(i);
    }
    Tree st(n);
    rep(i,0,q) {
        int qt; cin >>qt;
        if(qt==0) {
            int l,r,x; cin >>l >>r >>x; l--;
            if(x==0) {
                auto it = s.lower_bound(l);
                vi er;
                while(it!=s.end() && (*it)<r) {
                    er.push_back(*it);
                    it++;
                }
                for(auto eri: er) {
                    s.erase(eri);
                }
            } else {
                st.update(l, r-1);
            }
        } else {
            int j; cin >>j; j--;
            if(s.count(j)) {
                auto it = s.lower_bound(j);
                int l = 0, r = n;
                // debug() <<imie(l) imie(r);
                auto pr = it;
                if(pr!=s.begin()) {
                    pr--;
                    l = (*pr)+1;
                }
                auto nx = it;
                nx++;
                if(nx!=s.end()) {
                    r = (*nx);
                }
                // debug() <<imie(s);
                // debug() <<imie(l) imie(j+1) imie(r);
                // debug() <<imie(st.query(l,j+1));
                if(st.query(l,j+1) < r) {
                    cout <<"YES\n";
                } else {
                    cout <<"N/A\n";
                }
            } else {
                cout <<"NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}