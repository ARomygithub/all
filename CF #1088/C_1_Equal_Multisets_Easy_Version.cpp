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
int n,k,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,k) {
        // int st = i;
        for(int j=i;j+k<n;j+=k) {
            if(a[j]==a[j+k]) {
                if(b[j] != -1 && b[j+k]!=-1) {
                    if(b[j] != b[j+k]) {
                        cout <<"NO\n";
                        return;
                    }
                } else if(b[j] != -1) {
                    b[j+k] = b[j];
                } else if(b[j+k] !=-1) {
                    b[j] = b[j+k];
                    if(b[i]==-1) {
                        b[i] = b[j];
                    }
                }
            } else {
                if(b[j]==-1) {
                    b[j] = a[j];
                    if(b[i]==-1) {
                        b[i] = b[j];
                    }
                }
                if(b[j+k]==-1) {
                    b[j+k] = a[j+k];
                }
                if(b[j]!=a[j] || b[j+k]!=a[j+k]) {
                    cout <<"NO\n";
                    return;
                }
            }
        }
    }
    vi cta(n+1,0), ctb(n+1,0);
    rep(i,0,k) {
        cta[a[i]]++;
    }
    rep(i,0,k) {
        if(b[i]!=-1) {
            ctb[b[i]]++;
        }
    }
    rep(i,0,n+1) {
        if(ctb[i] > cta[i]) {
            cout <<"NO\n";
            return;
        }
    }
    cout <<"YES\n";
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