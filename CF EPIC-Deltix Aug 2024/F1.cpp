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

const int mxn=2e7;
int n,m,t;
vi fp;
map<pii,bool> mp;
ll ans, l, f;

bool e(pii nx) {
    return nx.fi<=n&&nx.se<=n&&nx.fi>=nx.se&&(__gcd(nx.fi,nx.se)==1)&&(!mp.count(nx));
}

void dfs(int a, int b) {
    // cout <<"a,b: " <<a <<" " <<b <<endl;
    mp[{a,b}] = 1;
    max_self(ans, l*a+f*b);
    pii nx = {a+1,b};
    if(e(nx)) {
        dfs(nx.fi,nx.se);
    }
    nx = {a,b+1};
    if(e(nx)) {
        dfs(nx.fi,nx.se);
    }
}

void solve() {
    cin >>n >>m >>l >>f;
    if(l<f) swap(l,f);
    mp.clear();
    ans = 0;
    int p = 1, q=1;
    auto it = upper_bound(fp.begin(),fp.end(), n);
    if(it!=fp.begin()) {
        it--;
        p = *it;
        if(it!=fp.begin()) {
            it--;
            q = *it;
        }
    }
    rep(j,q,p) {
        if(e({p,j})) {
            dfs(p, j);
        }
    }
    rep(i,p,n+1) {
        if(e({i,q})) {
            dfs(i,q);
        }
    }
    if(n<=10) {
        dfs(1,1);
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> isComp(mxn+1,0);
    rep(i,2,mxn+1) {
        if(!isComp[i]) {
            fp.push_back(i);
            for(ll j=i*2;j<=mxn;j+=i) {
                isComp[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}