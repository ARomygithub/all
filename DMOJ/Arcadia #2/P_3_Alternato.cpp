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
    vector<bool> pok(n,0), sok(n,0);
    pok[0] = 1;
    rep(i,1,n) {
        if(!pok[i-1]) break;
        if(i==1) {
            if(a[i]!=a[0]) {
                pok[1] = 1;
            }
            continue;
        }
        if(a[i]!=a[i-1] && (a[i-1] < min(a[i-2],a[i]) || a[i-1]> max(a[i-2],a[i]))) {
            pok[i] = 1;
        }
    }
    sok[n-1] = 1;
    per(i,n-2,-1) {
        if(!sok[i+1]) break;
        if(i==n-2) {
            if(a[i]!=a[i+1]) {
                sok[i] = i;
            }
            continue;
        }
        if(a[i]!=a[i+1] && (a[i+1] < min(a[i+2],a[i]) || a[i+1]> max(a[i+2],a[i]))) {
            sok[i] = 1;
        }        
    }
    if(pok[n-1]) {
        cout <<"0\n";
    } else {
        int ans = -1;
        rep(i,0,n) {
            bool ok = 1;
            if(i>0) {
                ok = ok && pok[i-1];
            }
            if(i+1<n) {
                ok = ok && sok[i+1];
            }
            bool mx = 1, mn = 1;
            if(i>0) {
                mx = mx && (a[i]+1 > a[i-1]);
                mn = mn && (a[i]-1 < a[i-1]);
                if(i>1) {
                    mx = mx && (a[i-1]<a[i-2]);
                    mn = mn && (a[i-1]>a[i-2]);
                }
            }
            if(i+1<n) {
                mx = mx && (a[i]+1 > a[i+1]);
                mn = mn && (a[i]-1 < a[i+1]);
                if(i+2<n) {
                    mx = mx && (a[i+1]<a[i+2]);
                    mn = mn && (a[i+1]>a[i+2]);
                }
            }
            if(!(mx || mn)) {
                ok = 0;
            }
            if(ok) {
                ans = 1;
                break;
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}