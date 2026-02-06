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

const int mxn=1e6;
int n,c,t;
int a[mxn];

void solve() {
    cin >>n >>c;
    set<int> s;
    rep(i,0,n) {
        cin >>a[i];
        s.insert(a[i]);
    }
    auto it = s.begin();
    if((*it)!=1) {
        cout <<"No\n";
        return;
    }
    vi pr(c+1,0);
    vector<bool> ada(c+1,0);
    for(auto si: s) {
        pr[si]++;
        ada[si] = 1;
    }
    rep(i,2,c+1) {
        pr[i] += pr[i-1];
    }
    bool ok = 1;
    rep(i,2,c+1) {
        if(ada[i]) {
            for(ll j=i*2;j<=c;j+=i) {
                if(pr[min(1ll*c,j+i-1)] - pr[j-1]>0) {
                    if(!ada[j/i]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(!ok) break;
        }
    }
    if(ok) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
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