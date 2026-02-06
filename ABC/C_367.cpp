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

const int mxn=8;
int n,k;
int r[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>r[i];
    }
    vi sp(n+1);
    sp[n] = 1;
    per(i,n-1,-1) {
        sp[i] = sp[i+1]*(r[i]+1);
    }
    rep(st,0,sp[0]) {
        vi v;
        int s = 0;
        bool ok = 1;
        rep(j,0,n) {
            int cur = (st%sp[j])/sp[j+1];
            v.push_back(cur);
            s += cur;
            ok = ok && (cur!=0);
            if(!ok) break;
        }
        if(!ok) continue;
        if((s%k)==0) {
            rep(i,0,sz(v)) {
                cout <<v[i] <<" \n"[i==sz(v)-1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}