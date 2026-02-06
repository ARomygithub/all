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

const int mxn=1e3;
int n,m,t;
int a[mxn][mxn],b[mxn][mxn];

bool slv(int bit) {
    set<pair<int,vector<bool>>> ct;
    ct.insert({0,vector<bool>(m,0)});
    vector<bool> udh(n,0);
    auto ins = [&](int i) -> void {
        vector<bool> cur(m,0);
        int x = 0;
        rep(j,0,m) {
            cur[j] = (b[i][j]>>bit)&1;
            x += cur[j];
        }
        ct.insert({x,cur});
    };
    vi idx(n);
    iota(all(idx),0);
    vi xx(n,0);
    rep(i,0,n) {
        rep(j,0,m) {
            xx[i] += ((b[i][j]>>bit)&1);
        }
    }
    sort(all(idx), [&](int i, int j) -> bool {
        return xx[i]<xx[j];
    });
    rep(i,0,n) {
        bool hrs = 0;
        rep(j,0,m) {
            int cura = (a[i][j]>>bit)&1;
            int curb = (b[i][j]>>bit)&1;
            if(cura==1 && curb==0) {
                hrs = 1;
                break;
            }
        }
        if(hrs) {
            udh[i] = 1;
            ins(i);
        }
    }
    rep(i,0,n) {
        bool ok = 1;
        rep(j0,0,n) {
            int j = idx[j0];
            if(udh[j]) continue;
            auto& cti = *(--ct.end());
            bool oki = 1;
            rep(k,0,m) {
                int curi = (b[j][k]>>bit)&1;
                int curi0 = (a[j][k]>>bit)&1;
                if(cti.se[k] && (curi==0)) {
                    oki = 0;
                    break;
                } else if((!cti.se[k]) && curi0==0 && curi==1) {
                    oki = 0;
                    break;
                }
            }
            if(!oki) {
                udh[j] = 1;
                ins(j);
                ok = 0;
                break;
            }
        }
        if(ok) break;
    }
    auto it = ct.begin();
    auto it2 = it; it2++;
    bool ok = 1;
    while(it2!=ct.end()) {
        auto& [xv,v] = *it;
        auto& [xvn,vn] = *it2;
        bool oki = 1;
        rep(j,0,m) {
            if(vn[j]==0 && v[j]==1) {
                oki = 0;
                break;
            }
        }
        if(!oki) {
            // debug() <<imie(v);
            // debug() <<imie(vn);
            ok = 0;
            break;
        }
        it++; it2++;
    }
    return ok;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }

    rep(i,0,n) {
        rep(j,0,m) {
            cin >>b[i][j];
        }
    }
    bool ok = 1;
    rep(bit,0,30) {
        ok = ok && slv(bit);
    }
    if(ok) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}