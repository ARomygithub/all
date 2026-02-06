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

const int mxn=2e5;
const ll mod=998244353;
int n,m,t;
int a[mxn];

int relPrime(int mi, vector<int>& vp) {
    ll ct = 0;
    rep(bit,0,1<<(sz(vp))) {
        ll u = 1, tmp=0;
        rep(j,0,sz(vp)) {
            if((bit>>j)&1) {
                u *=vp[j];
                tmp++;
            }
        }
        if(tmp%2) {
            ct -= (mi/u);
        } else {
            ct += (mi/u);
        }
    }
    return ct;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    int u = a[0];
    for(int i=2;i*i<=u;i++) {
        if((u%i)==0) {
            s.insert(i);
            while((u%i)==0) {
                u /=i;
            }
        }
    }
    if(u>1) {
        s.insert(u);
    }
    ll ans = 1;
    rep(i,1,n) {
        if((a[i-1]%a[i])==0) {
            int rat = a[i-1]/a[i];
            if(rat==1) {
                ans = ans*(1ll*m/a[i])%mod;
            } else {
                vector<int> vp;
                for(auto si: s) {
                    if((rat%si)==0) {
                        vp.push_back(si);
                    }
                }
                int ct = relPrime(m/a[i], vp);
                ans = ans*ct%mod;
                vector<int> toEr;
                for(auto si: s) {
                    if((a[i]%si)!=0) {
                        toEr.push_back(si);
                    }
                }
                for(auto er: toEr) {
                    s.erase(er);
                }
            }
        } else {
            cout <<"0\n";
            return;
        }
    }
    cout <<ans <<"\n";
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