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

const int mxn=3e3;
const ll inf = 1e18;
int n,w;
int v[mxn],wi[mxn];

template <class F>
vector<ll> monotone_maxima(F &f, int h, int w) {
    vector<ll> ret(h);
    auto sol = [&](auto &&self, const int l_i, const int r_i, const int l_j, const int r_j) -> void {
        const int m_i = (l_i + r_i) / 2;
        int max_j = l_j;
        ll max_val = -inf;
        for (int j = l_j; j <= r_j; ++j) {
            const ll v = f(m_i, j);
            if (v > max_val) {
                max_j = j;
                max_val = v;
            }
        }
        ret[m_i] = max_val;
        if (l_i <= m_i - 1) {
            self(self, l_i, m_i - 1, l_j, max_j);
        }
        if (m_i + 1 <= r_i) {
            self(self, m_i + 1, r_i, max_j, r_j);
        }
    };
    sol(sol, 0, h - 1, 0, w - 1);
    return ret;
}

vector<ll> max_plus_convolution(const vector<ll> &a, const vector<ll> &b) {
    const int n = (int)a.size(), m = (int)b.size();
    auto f = [&](int i, int j) {
        if (i < j or i - j >= m) {
            return -inf;
        }
        return a[j] + b[i - j];
    };
    return monotone_maxima(f, n + m - 1, n);
}

void solve() {
    cin >>n >>w;
    rep(i,0,n) {
        cin >>wi[i] >>v[i];
    }
    vector<ll> ret(w+1,0);
    rep(i,0,n) {
        ll bwh = w/wi[i];
        vector<ll> v1(w+1,0);
        ll pr = 0;
        rep(j,1,bwh+1) {
            // max_self(pr, 1ll*v[i]*j - 1ll*j*j);
            pr = 1ll*v[i]*j - 1ll*j*j;            
            v1[wi[i]*j] = pr;
            if(j<bwh) {
                rep(k,0,wi[i]) {
                    v1[wi[i]*j+k] = pr;
                }
            } else {
                rep(k,0,wi[i]) {
                    v1[min(wi[i]*j+k,w)] = pr;
                }
            }
        } 
        ret = max_plus_convolution(ret, v1);
        ret.resize(min(w+1,sz(ret)));
        // debug() <<imie(ret);
    }
    ll ans = 0;
    rep(i,0,sz(ret)) {
        max_self(ans,ret[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}