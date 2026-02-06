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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
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

const int mxn=4e5;
const int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
int n,m;

int to_id(pii ij) {
    return ij.fi*m+ij.se;
}

pii from_id(int id) {
    return {id/m, (id%m)};
}

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

void solve() {
    cin >>n >>m;
    vector p(n, vector<int>(m));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>p[i][j];
        }
    }
    vector ans(n, vector<int>(m));
    UF uf(n*m);
    vector<ipii> v;
    rep(i,0,n) {
        rep(j,0,m) {
            v.push_back({p[i][j],{i,j}});
        }
    }
    sort(v.begin(), v.end());
    for(int ii=0; ii<sz(v);) {
        int jj = ii;
        while(jj<sz(v) && v[jj].fi==v[ii].fi) {
            jj++;
        }
        rep(k,ii,jj) {
            auto [i,j] = v[k].se;
            rep(k2,0,4) {
                int i2 = i+di[k2], j2=j+dj[k2];
                if(e(i2,j2) && v[k].fi>=p[i2][j2]) {
                    uf.join(to_id({i,j}), to_id({i2,j2}));
                }
            }
            ans[i][j] = uf.size(to_id({i,j}));
        }
        map<int,int> mp;
        rep(k,ii,jj) {
            auto [i,j] = v[k].se;
            max_self(mp[uf.find(to_id({i,j}))], uf.size(to_id({i,j})));
        }
        rep(k,ii,jj) {
            auto [i,j] = v[k].se;
            max_self(ans[i][j], mp[uf.find(to_id({i,j}))]);
        }
        ii = jj;
    }
    rep(i,0,n) {
        rep(j,0,m) {
            cout <<ans[i][j] <<" \n"[j==m-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}