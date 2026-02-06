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
int n,m,t;

vi pi(const vi& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

int match(const vi& s, const vi& pat) {
    vi cur;
    for(auto pati: pat) {
        cur.push_back(pati);
    }
    cur.push_back(2e9);
    for(auto si: s) {
        cur.push_back(si);
    }
    vi p = pi(cur);
    int res = 0;
    rep(i,sz(p)-sz(s),sz(p))
        if (p[i] == sz(pat)) res++;
    return res;
}


void solve() {
    cin >>n >> m;
    vi a(n), b(m);
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    vi sn(n-1), sm(m-1);
    rep(i,0,n-1) {
        sn[i] = a[i+1]-a[i];
    }
    rep(i,0,m-1) {
        sm[i] = b[i+1]-b[i];
    }
    if(m==1) {
        cout <<n <<"\n";
    } else if(n==1) {
        cout <<"0\n";
    } else {
        int ct = match(sn, sm);
        cout <<ct <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}