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

const int mxn=1e5,mxa=4e5;
int n,t;
int a[mxn];
set<int> pr;
int fp[mxa+1];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        if(pr.count(a[i])) {
            s.insert(a[i]);
        }
    }
    if(sz(s)>1) {
        cout <<"-1\n";
    } else if(sz(s)==1) {
        bool ok = 1;
        int ans = *s.begin();
        rep(i,0,n) {
            if(a[i]==ans) continue;
            if(1ll*fp[a[i]]*ans > a[i]) {
                set<int> cand;
                int cur = 3*ans;
                int u = a[i];
                while(u>1) {
                    cand.insert(fp[u]);
                    u /= fp[u];
                }
                for(auto candi : cand) {
                    int ats = ans + (candi - (ans%candi));
                    ats *= 2;
                    min_self(cur, ats);
                }
                if(cur > a[i]) {
                    ok = 0;
                    break;
                } 
            }
        }
        if(!ok) {
            cout <<"-1\n";
        } else {
            cout <<ans <<"\n";
        }
    } else {
        int ans = mxa;
        rep(i,0,n) {
            min_self(ans, fp[a[i]]);
        }
        cout <<ans <<"\n";
    }
}

void init() {
    vector<bool> comp(mxa+1,0);
    rep(i,2,mxa+1) {
        if(!comp[i]) {
            pr.insert(i);
            fp[i] = i;
            for(ll j=i*2;j<=mxa;j+=i) {
                comp[j] = 1;
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j], i);
                }
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