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

const int mxn=2e5;
int n,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
    }
    rep(i,0,n) {
        cin >>b[i]; b[i]--;
    }
    vi pos(n);
    rep(i,0,n) {
        pos[a[i]] = i;
    }
    rep(i,0,n) {
        b[i] = pos[b[i]];
    }
    vector<pii> v;
    int sm = -1;
    rep(i,0,n) {
        if(b[i]>i && b[b[i]]==i) {
            v.push_back({i,b[i]});
        } else if(b[i]==i) {
            sm = i;
        }
    }
    if(sz(v) < (n/2)) {
        cout <<"-1\n";
    } else {
        vi p(n);
        int id = 0;
        rep(i,0,sz(v)) {
            auto [l,r] = v[i];
            p[id] = l;
            p[n-1-id] = r;
            id++;
        }
        if(sm!=-1) {
            p[id] = sm;
        }
        vector<pii> ans;
        vi p1(n);
        iota(all(p1),0);
        vi ip1(n);
        iota(all(ip1),0);
        rep(i,0,n) {
            if(p1[i]!=p[i]) {
                int j = ip1[p[i]];
                ans.push_back({i,j});
                swap(ip1[p1[i]],ip1[p1[j]]);
                swap(p1[i],p1[j]);
            }
        }
        cout <<sz(ans) <<"\n";
        for(auto [l,r]: ans) {
            cout <<l+1 <<" " <<r+1 <<"\n";
        }
    }
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