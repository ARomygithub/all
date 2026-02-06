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

const int mxn=5e3;
const ll mod=998244353;
int n,q;
int p[mxn],v[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,q) {
        cin >>p[i] >>v[i]; p[i]--;
    }
    vector<int> pos(q,-1);
    ll ans = 1;
    per(i,q-1,-1) {
        set<int> sp;
        rep(j,0,i) {
            if(v[j]>v[i]) {
                if(p[j]>=p[i]) {
                    sp.insert(1);
                }
                if(p[j]<=p[i]) {
                    sp.insert(0);
                }
            }
        }
        if(pos[i]==-1) {
            if(sz(sp)==2) {
                cout <<"0\n";
                return;
            } else if(sz(sp)) {
                rep(j,0,i) {
                    if(v[j]>v[i]) {
                        int cur = *sp.begin();
                        if(pos[j]!=-1 && pos[j]!=cur) {
                            cout <<"0\n";
                            return;
                        }
                        pos[j] = cur;
                    }
                }
                pos[i] = 1- (*sp.begin());
            } else {
                ans =ans*2ll%mod;
            }
        } else {
            for(auto vlj: sp) {
                if(vlj==pos[i]) {
                    cout <<"0\n";
                    return;
                }
            }
            if(sz(sp)) {
                rep(j,0,i) {
                    if(v[j]>v[i]) {
                        int cur = *sp.begin();
                        if(pos[j]!=-1 && pos[j]!=cur) {
                            cout <<"0\n";
                            return;
                        }
                        pos[j] = cur;
                    }
                }                
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}