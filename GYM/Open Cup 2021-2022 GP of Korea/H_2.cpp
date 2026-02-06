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
 
const int mxn=50;
int n;
int x[mxn], a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        rep(j,i+1,n) {
            if(a[i]!=a[j]) {
                int len = abs(x[i]-x[j]);
                for(int k=1;k*k<=len;k++) {
                    if((len%k)==0) {
                        if(k>n) s.insert(k);
                        if(len/k>n) s.insert(len/k);
                    }
                }
            }
        }
    }
    rep(i,1,n+1) {
        vector<int> v(i,-1);
        bool ok = 0;
        rep(j,0,n) {
            int ii = ((x[j]%i)+i)%i;
            if(v[ii]!=-1 && v[ii]!=a[j]) {
                ok = 1;
                break;
            }
            v[ii] = a[j];
        }
        if(ok) {
            s.insert(i);
            continue;
        }
        ok = 1;
        rep(j,0,i) {
            if(v[j]==-1) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            continue;
        }
        ok = 0;
        rep(j,1,(i/2)+1) {
            if((i%j)==0) {
                bool temp = 1;
                rep(k,j,i) {
                    temp &= v[k]==v[k-j];
                }
                if(temp) {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok) {
            s.insert(i);
        }
    }
    ll sum = 0;
    for(int si: s) {
        sum +=1ll*si; 
    }
    cout <<sz(s) <<" " <<sum <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}