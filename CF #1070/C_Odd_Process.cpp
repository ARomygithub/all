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
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi o, e;
    rep(i,0,n) {
        if(a[i]%2) {
            o.push_back(a[i]);
        } else {
            e.push_back(a[i]);
        }
    }
    sort(all(o),greater<int>());
    sort(all(e),greater<int>());
    vector<ll> pr(sz(e)+1,0);
    rep(i,1,sz(pr)) {
        pr[i] = pr[i-1] + e[i-1];
    }
    vector<ll> ans(n,0);
    rep(i,0,n) {
        if(sz(o)) {
            int sisa = max(1, (i+1)-sz(e));
            if((sisa%2)==0) {
                sisa++;
            }
            if(sisa <= sz(o)  && (i+1)-sisa>=0) {
                ans[i] = o[0] + pr[(i+1)-sisa];
            }
        } else {
            break;
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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