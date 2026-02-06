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
string s;

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
    cin >>s;
    int n = sz(s);
    auto p = manacher(s);
    vi deg(n,0);
    vi v;
    rep(i,0,n) {
        int le = i - p[0][i];
        int ri = i + p[0][i]-1;
        if(p[0][i]) {
            if(le==0) {
                v.push_back(ri);
            }
        }
        le = i - p[1][i];
        ri = i + p[1][i];
        if(le==0) {
            v.push_back(ri);
        }
    }
    sort(all(v));
    int ans = 0;
    rep(i,0,sz(v)) {
        int x = (v[i]+1)/2 -1;
        deg[v[i]] = 1;
        if(x>=0) {
            deg[v[i]] = deg[x]+1;
        }
        ans += deg[v[i]];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}