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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const ll mod = 1e9+7;
ll det(vector<vector<ll>>& a) {
    int n = sz(a); ll ans = 1;
    rep(i,0,n) {
        rep(j,i+1,n) {
            while (a[j][i] != 0) { // gcd step
                ll t = a[i][i] / a[j][i];
                if (t) rep(k,i,n)
                    a[i][k] = (a[i][k] - a[j][k] * t) % mod;
                swap(a[i], a[j]);
                ans *= -1;
            }
        }
        ans = ans * a[i][i] % mod;
        if (!ans) return 0;
    }
    return (ans + mod) % mod;
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
typedef pair<int,pii> ipii;

const int mxn=300;
int n;
int a[mxn][mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>a[i][j];
        }
    }
    vector<ipii> v;
    rep(i,0,n) {
        rep(j,i+1,n) {
            if(a[i][j]!=a[j][i] && a[i][j]!=-1 && a[j][i]!=-1) {
                cout <<"0\n";
                return;
            } else {
                int aij = max(a[i][j],a[j][i]);
                v.push_back({aij,{i,j}});
            }
        }
    }
    sort(v.begin(),v.end(),greater<ipii>());
    // debug() <<imie(v);
    UF uf(n);
    int idx = 0;
    bool ok = 1;
    while(idx<sz(v)) {
        if(v[idx].fi==-1) break;
        if(v[idx].fi==1) {
            ok = uf.join(v[idx].se.fi, v[idx].se.se);
            if(!ok) {
                cout <<"0\n";
                return;
            }
        }
        idx++;
    }
    map<int,int> id;
    int idi = 0;
    rep(i,0,n) {
        int x = uf.find(i);
        if(!id.count(x)) {
            // cout <<"tes" <<endl;
            id[x] = idi++;
        }
    }
    vector mat(idi, vector<ll>(idi,0ll));
    while(idx<sz(v)) {
        int x = id[uf.find(v[idx].se.fi)];
        int y = id[uf.find(v[idx].se.se)];
        mat[x][y]--, mat[y][y]++;
        mat[y][x]--, mat[x][x]++;
        idx++;
    }
    // rep(i,0,sz(mat)) {
    //     debug() <<imie(mat[i]);
    // }
    // debug() <<imie(mat);
    mat.pop_back();
    rep(i,0,sz(mat)) {
        mat[i].pop_back();
    }
    ll ans = det(mat);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}