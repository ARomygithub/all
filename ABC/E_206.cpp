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
int l,r;
int fp[mxn+1], ct[mxn+1], subfct[mxn+1];

void solve() {
    cin >>l >>r;
    // cout <<"tes\n" <<flush;
    ll ans = 0;
    rep(i,l,r+1) {
        vector<int> prime;
        int u = i;
        int fct = 1;
        while(u!=1) {
            int v = fp[u];
            // cout <<u <<" " <<v <<endl;
            int ex = 0;
            while((u%v)==0) {
                u /=v;
                ex++;
            }
            fct *= (ex+1);
            prime.push_back(v);
        }
        if(i>l) {
            // cout <<"add" <<endl;
            ll ansi = 0;
            rep(bit,1,1<<sz(prime)) {
                u = 1;
                int ctbit = 0;
                rep(j,0,sz(prime)) {
                    if((bit>>j)&1) {
                        u *= prime[j];
                        ctbit++;
                    }
                }
                if(ctbit%2) {
                    ansi += ct[u];
                } else {
                    ansi -= ct[u];
                }
            }
            // cout <<i <<" " <<ansi <<endl;
            ansi -= subfct[i];
            ans += ansi;
        }
        rep(bit,1,1<<sz(prime)) {
            u = 1;
            rep(j,0,sz(prime)) {
                if((bit>>j)&1) {
                    u *= prime[j];
                }
            }
            // cout <<u <<endl;
            ct[u]++;
        }
        if(i>1) {
            for(int j=i*2;j<=mxn;j+=i) {
                subfct[j]++;
            }
        }
    }
    // cout <<"tes" <<endl;
    ans *=2ll;
    cout <<ans <<"\n";
}

void init() {
    vector<bool> comp(mxn+1, 0);
    rep(i,2,mxn+1) {
        if(!comp[i]) {
            fp[i] = i;
            for(int j=i*2;j<=mxn;j+=i) {
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
    init();
    solve();
}