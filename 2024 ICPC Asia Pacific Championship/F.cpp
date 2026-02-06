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

const int mxn=1e6;
int n,t;
int a[mxn];
pii ans = {1e9,1};

void solveFor(int k) {
    // if(ans.fi==ans.se) return;
    vector<int> sk(k,0);
    rep(i,0,n) {
        sk[i%k] += a[i];
    }
    set<pii> s;
    rep(i,0,k) {
        s.insert({sk[i],i});
    }
    pii mn = *s.begin();
    pii mx = *(--s.end());
    if(1ll*ans.fi*mn.fi > 1ll*mx.fi*ans.se) {
        ans = {mx.fi,mn.fi};
    }
    rep(i,1,n) {
        int ii = (i-1+k)%k;
        int jj = i%k;
        s.erase({sk[ii],ii});
        s.erase({sk[jj],jj});
        sk[ii] -= a[0];
        sk[jj] -= a[i];
        sk[ii] += a[i];
        sk[jj] += a[0];
        s.insert({sk[ii],ii});
        s.insert({sk[jj],jj});
        mn = *s.begin();
        mx = *(--s.end());
        if(1ll*ans.fi*mn.fi > 1ll*mx.fi*ans.se) {
            ans = {mx.fi,mn.fi};
        }        
    }
}

void solve() {
    ans = {1e9,1};
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int u = n;
    for(int i=2;i*i<=u;i++) {
        if((u%i)==0) {
            solveFor(i);
            while((u%i)==0) {
                u /=i;
            }
        }
    }
    if(u!=1) {
        solveFor(u);
    }
    int d = __gcd(ans.fi,ans.se);
    ans.fi /=d;
    ans.se /=d;
    cout <<ans.fi <<" " <<ans.se <<"\n";
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