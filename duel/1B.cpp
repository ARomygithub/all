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
int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(vi& vl, vi& vr) {
    vi w(n,0);
    for(auto& vli: vl) {
        w[vli-1] = 1;
    }
    for(auto& vri: vr) {
        w[vri-1] = 2;
    }
    cout <<"? ";
    rep(i,0,n) {
        cout <<w[i] <<" \n"[i==n-1];
    }
    cout <<flush;
    int ret; cin >>ret;
    return ret;
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    cin >>n;
    set<int> sab;
    vi vl(1, 1), vr(1, 2);
    int ret = ask(vl,vr);
    sab.insert(ret);
    vi vid(n);
    iota(all(vid),1);
    shuffle(all(vid), rng);
    rep(i,0,n) {
        vl[0] = vid[i];
        vr.clear();
        rep(j,1,n+1) {
            if(j!=vid[i]) {
                vr.push_back(j);
            }
        }
        int ret = ask(vl,vr);
        if(ret != (*sab.begin())*(n-1)) {
            vr.resize(1);
            rep(j,1,n+1) {
                if(j!=vid[i]) {
                    vr[0] = j;
                    ret = ask(vl,vr);
                    if(ret != (*sab.begin())) {
                        sab.insert(ret);
                        break;
                    }
                }
            }
            break;
        }
    }
    if(sz(sab)<2) {
        vector<pii> ed;
        rep(i,2,n+1) {
            ed.push_back({i-1,i});
        }
        cout <<"! " <<sz(ed) <<"\n";
        rep(i,0,sz(ed)) {
            cout <<ed[i].fi <<" " <<ed[i].se <<"\n";
        }
        cout <<flush;
        return;
    }
    UF uf(n+1);
    vector<bool> udh(n,0);
    function<void(int)> slv1;
    vector<pii> ed;
    function<void(vi&, int, int, int, int)> slv2;
    int a = *(sab.begin());
    int b = *(++sab.begin());
    slv2 = [&](vi& v, int l, int r, int u, int sm) -> void {
        int len = r-l+1;
        if(sm==a*len) {
            rep(i,l,r+1) {
                uf.join(vid[u], vid[v[i]]);
                ed.push_back({vid[u],vid[v[i]]});
            }
        } else if(sm==b*len) {
            ;
        } else {
            int mid = (l+r)/2;
            vl.clear(); vl.push_back(vid[u]);
            vr.clear(); 
            rep(i,l,mid+1) {
                vr.push_back(vid[v[i]]);
            }
            int sml = ask(vl,vr);
            slv2(v, l, mid, u, sml);
            slv2(v, mid+1, r, u, sm-sml);
        }
    };
    slv1 = [&](int i) -> void {
        udh[i] = 1;
        vi v;
        rep(j,0,n) {
            if((!udh[j]) && (!uf.sameSet(vid[i],vid[j]))) {
                v.push_back(j);
            }
        }
        if(sz(v)) {
            vl.clear(); vl.push_back(vid[i]);
            vr.clear(); 
            rep(j,0,sz(v)) {
                vr.push_back(vid[v[j]]);
            }
            int sm = ask(vl,vr);            
            slv2(v, 0, sz(v)-1, i, sm);
        }
        for(auto j: v) {
            if((!udh[j]) && uf.sameSet(vid[i],vid[j])) {
                slv1(j);
            }
        }
    };
    rep(i,0,n) {
        if(!udh[i]) {
            slv1(i);
        }
    }
    set<int> s;
    rep(i,1,n+1) {
        s.insert(uf.find(i));
    }
    if(sz(s)>1) {
        auto it = s.begin();
        auto it2 = it; it2++;
        while(it2!=s.end()) {
            ed.push_back({*it,*it2});
            it++; it2++;
        }
    }
    cout <<"! " <<sz(ed) <<"\n";
    rep(i,0,sz(ed)) {
        cout <<ed[i].fi <<" " <<ed[i].se <<"\n";
    }
    cout <<flush;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}