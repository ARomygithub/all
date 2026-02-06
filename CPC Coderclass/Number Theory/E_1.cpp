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

const int mxn=2e6,mxa=2e6;
int l,r;
vi phi, pr;

void solve() {
    cin >>l >>r;
    if(r>mxa) {
        int ans = 1;
        for(ll i=0;i<sz(pr) && 1ll*pr[i]*pr[i]<=r;i++) {
            int cur = 1;
            while((r%pr[i])==0) {
                r /= pr[i];
                cur *= pr[i];
            }
            ans *= (cur - cur/pr[i]);
        }
        if(r>1) {
            ans *= (r-1);
        }
        cout <<ans <<"\n";
        return;
    }
    rep(i,l,r+1) {
        cout <<phi[i] <<"\n";
    }
}

void init() {
    vi fp(mxa+1,mxa);
    phi.resize(mxa+1, 1);
    vector<bool> isComp(mxa+1,0);
    rep(i,2,mxa+1) {
        if(!isComp[i]) {
            pr.push_back(i);
            min_self(fp[i], i);
            phi[i] = i-1;
            for(ll j=i*2;j<=mxa;j+=i) {
                isComp[j] = 1;
                min_self(fp[j], i);
            }
        } else {
            int cur = 1;
            int u = i;
            int fpi = fp[i];
            while(fp[u]==fpi) {
                cur *=fpi;
                u /= fpi;
            }
            phi[i] = (cur - cur/fpi) * phi[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}