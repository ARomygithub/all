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
    int ct0 = 0;
    int fr0 = -1;
    rep(i,0,n) {
        if(a[i]==0) {
            ct0++;
            if(fr0==-1) {
                fr0 = i;
            }
        }
    }
    int ans = n-ct0;
    if(ct0>0) {
        int mx = 0;
        set<int> st;
        bool ok = 1;
        per(i,n-1,-1) {
            if(i==fr0) {
                st.insert(0);
                while(st.count(mx)) {
                    mx++;
                }
            } else {
                if(a[i]!=0) {
                    if(a[i]>=mx) {
                        st.insert(a[i]);
                        while(st.count(mx)) {
                            mx++;
                        }
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if(ok) {
            ans = n-ct0+1;
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