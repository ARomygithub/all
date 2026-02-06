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

const int mxn=500;
int n,m;
string s[mxn];

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi,2> p = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
        int t = r-i+!z;
        if (i<r) p[z][i] = min(t, p[z][l+t]);
        int L = i-p[z][i], R = i+p[z][i]-!z;
        while (L>=1 && R+1<n && s[L-1] == s[R+1])
            p[z][i]++, L--, R++;
        if (R>r) l=L, r=R;
    }
    return p;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector ct(n, vector<pii>(m,{0,0}));
    rep(i,0,n) {
        auto pal = manacher(s[i]);
        rep(j,0,m+1) {
            int hz = pal[0][j];
            int le = j-hz, ri = j+hz-1;
            rep(k,le,ri+1) {
                max_self(ct[i][k].fi, hz*2);
            }
        }
        rep(j,0,m) {
            int hz = pal[1][j];
            int le = j-hz, ri = j+hz;
            rep(k,le,ri+1) {
                max_self(ct[i][k].fi, hz*2+1);
            }
        }
    }
    rep(j,0,m) {
        string str = "";
        rep(i,0,n) {
            str += s[i][j];
        }
        auto pal = manacher(str);
        rep(i,0,n+1) {
            int hz = pal[0][i];
            int le = i-hz, ri = i+hz-1;
            rep(k,le,ri+1) {
                max_self(ct[k][j].se, hz*2);
            }
        }
        rep(i,0,n) {
            int hz = pal[1][i];
            int le = i-hz, ri = i+hz;
            rep(k,le,ri+1) {
                max_self(ct[k][j].se, hz*2+1);
            }
        }
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            max_self(ans, ct[i][j].fi*ct[i][j].se);
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