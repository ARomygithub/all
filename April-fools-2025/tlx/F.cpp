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

const int mxn=1e3;
int n,m;
ll k,a[mxn][mxn];

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

ll fastexpo(ll a, ll b, ll md) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}
using plii = pair<ll,pii>;

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    vector<plii> ed;
    rep(i,0,n) {
        rep(j,0,m) {
            int cur = i*m+j;
            if(j+1<m) {
                int nx = i*m+j+1;
                ll cs = fastexpo(a[i][j],a[i][j+1],k);
                cs = cs*fastexpo(a[i][j+1],a[i][j],k)%k;
                ed.push_back({cs,{cur,nx}});
            }
            if(i+1<n) {
                int nx = (i+1)*m+j;
                ll cs = fastexpo(a[i][j],a[i+1][j],k);
                cs = cs*fastexpo(a[i+1][j],a[i][j],k)%k;
                ed.push_back({cs,{cur,nx}});
            }
        }
    }
    sort(all(ed));
    UF uf(n*m);
    pii st = {-1,-1};
    // pii en = {-1,-1};
    for(auto [w,uv]: ed) {
        auto [u,v] = uv;
        if(uf.join(u,v)) {
            if(st.fi==-1) {
                st = {u/m, u%m};
                break;
            }
        }
    }
    st.fi++;
    st.se++;
    cout <<st.fi <<" " <<st.se <<" " <<st.fi <<" " <<st.se <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}