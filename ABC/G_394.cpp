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

const int mxn=500,mxq=2e5;
int n,m,f[mxn][mxn],q;
using pp = pair<pii,pii>;
// using ppp = pair<pp,pii>;
using ipp = pair<int,pp>;
int ans[mxq];

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

using ipii = pair<int,pii>;
vector<pii> v;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

int toId(int i, int j) {
    return i*m+j;
}

pii fromId(int id) {
    return {id/m, id%m};
}

// bef: st, blm connect. af: st.
void slv(RollbackUF& ruf, int st, int en, vector<ipp>& vq) {
    // debug() <<imie(st) imie(en);
    // debug() <<imie(vq);
    if(en-st<=1) return;
    int mid = (st+en)/2;
    int t0 = ruf.time();
    vector<ipp> vq0, vq1;
    rep(i,st,mid) {
        int curid = v[i].se;
        auto [x,y] = fromId(curid);
        rep(j,0,4) {
            int xx = x+di[j], yy = y+dj[j];
            if(e(xx,yy) && f[x][y]<=f[xx][yy]) {
                ruf.join(toId(x,y),toId(xx,yy));
            }
        }
    }
    int lvl = v[mid-1].fi;
    for(auto& [id,ay]: vq) {
        auto& [ab,yz] = ay;
        auto& [a,b] = ab;
        if(ruf.find(a)==ruf.find(b)) {
            vq0.push_back({id,ay});
            auto& [y,z] = yz;
            int cur = 0;
            int y2 = y;
            if(y2>lvl) {
                cur += y2-lvl;
                y2 = lvl;
            }
            cur += abs(y2-z);
            ans[id] = cur;
        } else {
            vq1.push_back({id,ay});
        }
    }
    if(sz(vq0)>0 && mid>st) {
        ruf.rollback(t0);
        slv(ruf, st, mid, vq0);
        rep(i,st,mid) {
            int curid = v[i].se;
            auto [x,y] = fromId(curid);
            rep(j,0,4) {
                int xx = x+di[j], yy = y+dj[j];
                if(e(xx,yy) && f[x][y]<=f[xx][yy]) {
                    ruf.join(toId(x,y),toId(xx,yy));
                }
            }
        }  
    }
    if(sz(vq1)>0 && mid<en) {
        slv(ruf,mid,en,vq1);
    }
    ruf.rollback(t0);
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>f[i][j];
            v.push_back({f[i][j],toId(i,j)});
        }
    }
    sort(all(v), greater<pii>());
    cin >>q;
    vector<ipp> qry;
    int ls = v.back().fi;
    rep(i,0,q) {
        int a,b,c,d,y,z; cin >>a >>b >>y >>c >>d >>z; a--,b--,c--,d--;
        qry.push_back({i,{{toId(a,b),toId(c,d)},{y,z}}});
        int y2 = y;
        int cur = 0;
        if(y2>ls) {
            cur += y2-ls;
            y2 = ls;
        }
        cur += abs(y2-z);
        ans[i] = cur;
    }
    RollbackUF ruf(n*m);
    slv(ruf, 0, n*m, qry);
    rep(i,0,q) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}