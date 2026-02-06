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

const int mxn=1e4;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> v;
    rep(i,0,n-1) {
        int xr = a[i]^a[i+1];
        if(xr==0) {
            v.push_back({-1,-1});
            continue;
        }
        per(j,30,-1) {
            if((xr>>j)&1) {
                v.push_back({(a[i]>>j)&1, j});
                break;
            }
        }
    }
    // debug() <<imie(v);
    vector<vi> pr, sf;
    rep(i,0,sz(v)) {
        vi cur(31,-1);
        if(i>0) {
            cur = pr.back();
        }
        if(v[i].se!=-1) {
            auto [val,j] = v[i];
            if(cur[j]!=-1 && cur[j]!=val) {
                break;
            }
            cur[j] = val;
        }
        pr.push_back(cur);
    }
    per(i,sz(v)-1,-1) {
        vi cur(31, -1);
        if(i+1<sz(v)) {
            cur = sf.back();
        }
        if(v[i].se!=-1) {
            auto [val, j] = v[i];
            val = 1-val;
            if(cur[j]!=-1 && cur[j]!=val) {
                break;
            }
            cur[j] = val;
        }
        sf.push_back(cur);
    }
    // debug() <<imie(pr);
    // debug() <<imie(sf);
    rep(i,0,sz(v)-1) {
        if(i<sz(pr) && sz(v)-2-i<sz(sf)) {
            vi bit(31,-1);
            bool ok = 1;
            rep(j,0,31) {
                if(pr[i][j]!=-1 && sf[sz(v)-2-i][j]!=-1 && pr[i][j]!=sf[sz(v)-2-i][j]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                int ans = 0;
                rep(j,0,31) {
                    if(pr[i][j]==1 || sf[sz(v)-2-i][j]==1) {
                        ans += (1<<j);
                    }
                }
                cout <<ans <<"\n";
                return;
            }
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}