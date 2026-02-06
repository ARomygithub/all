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
int n,m;
int a[mxn],x[mxn];
vector<vi> mask;
vi xr;
using ipii = pair<int,pii>;

void slv(vector<pii>& v, int k, vi& curMask, int curxr) {
    int mn = k;
    rep(j,0,k) {
        if(curMask[j]!=-1) {
            mn = j;
            break;
        }
    }
    vector<ipii> upd;
    int mn0 = mn;
    for(auto [ai,aj]: v) {
        int aij = ai^aj;
        per(j,k-1,-1) {
            if((aij>>j)&1) {
                upd.push_back({j, {(ai>>j)&1, (aj>>j)&1}});
                min_self(mn0, j);
                break;
            }
        }
    }
    // sort(all(upd));
    // if(sz(upd)) {
    //     min_self(mn0, upd[0].fi);
    // }
    vector<pii> v2;
    rep(i,0,sz(upd)) {
        if(upd[i].fi>mn0 || upd[i].fi>=mn) {
            int j = upd[i].fi;
            if(curMask[j]==-1 || curMask[j]==upd[i].se.fi) {
                curMask[j] = upd[i].se.fi;
            } else {
                curMask[j] = 2;
            }
        } else {
            v2.push_back(v[i]);
        }
    }
    if(sz(v2)) {
        int ncurxr = curxr | (1<<mn0);
        vi ncurMask(curMask);
        slv(v2, mn0, ncurMask, ncurxr);
        for(auto [ai, aj]: v2) {
            int j = mn0;
            int bi = (ai>>j)&1;
            int bj = (aj>>j)&1;
            if(curMask[j]==-1 || curMask[j]==bi) {
                curMask[j] = bi;
            } else {
                curMask[j] = 2;
            }
        }
    }
    mask.push_back(curMask);
    xr.push_back(curxr);
}

// blm handle kasus a[i]=a[j], maka ada constraint tambahan harus persis sama. dan all p bisa lah (karena di rearrange)
void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>x[i];
    }
    vi curMask(30, -1);
    int curxr = 0;
    rep(i,0,n-2) {
        int aij = a[i]^a[i+2];
        per(j,29,-1) {
            if((aij>>j)&1) {
                if(curMask[j]==-1 || curMask[j]==((a[i]>>j)&1)) {
                    curMask[j] = ((a[i]>>j)&1);
                } else {
                    curMask[j] = 2; //invalid
                }
                break;
            }
        }
    }
    vector<pii> v;
    rep(i,0,n-1) {
        if(a[i]!=a[i+1]) {
            v.push_back({a[i],a[i+1]});
        }
    }
    slv(v, 30, curMask, curxr);
    ll ans = 0;
    vi mn(sz(xr), 30);
    rep(i,0,sz(xr)) {
        rep(j,0,30) {
            int ms = mask[i][j], cxr = (xr[i]>>j)&1;
            if(ms!=-1 || cxr==1) {
                mn[i] = j;
                break;
            }
        }
    }
    debug() <<imie(mn);
    debug() <<imie(mask);
    debug() <<imie(xr);
    rep(i,0,sz(xr)) {
        map<int,int> mp;
        rep(j,0,m) {
            bool ok = 1;
            rep(k,0,30) {
                if(mask[i][k]!=-1 && mask[i][k]!=((x[j]>>k)&1)) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) continue;
            int lwn = ((x[j]^xr[i]) >>mn[i]);
            ans += mp[lwn];
            int cur = (x[j]>>mn[i]);
            mp[cur]++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}