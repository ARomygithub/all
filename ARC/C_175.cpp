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

const int mxn=5e5;
int n;
int l[mxn],r[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>l[i] >>r[i];
    }
    vi ans(n,-1);
    int st = 0;
    rep(i,0,n-1) {
        if(l[i]>r[i+1]) {
            if(st!=-1) {
                st = -1;
                ans[i] = l[i];
            }
        } else if(r[i]<l[i+1]) {
            if(st!=1) {
                // cout <<i <<endl;
                st = 1;
                ans[i] = r[i];
            }
        }
    }
    int le=-1,ri=-1;
    for(int i=0;i<n;) {
        if(ans[i]!=-1) {
            if(r[i]<l[i+1] && le!=-1 && le<ans[i]) {
                ans[i] = max(le,l[i]);
            }
            le = ans[i];
            i++;
            continue;
        }
        int j=i;
        while(j<n && ans[j]==-1) {
            j++;
        }
        if(j==n) {
            ri = -1;
        } else {
            ri = ans[j];
        }
        if(le==-1 && ri==-1) {
            int lx=0,rx=1e9;
            rep(k,i,j) {
                max_self(lx, l[k]);
                min_self(rx, r[k]);
            }
            rep(k,i,j) {
                ans[k] = lx;
            }
        } else if(le==-1) {
            per(k,j-1,i-1) {
                ans[k] = clamp(ri, l[k], r[k]);
                ri = ans[k];
            }
            le = ans[j-1];
        } else {
            rep(k,i,j) {
                ans[k] = 1e9;
                if(le!=-1) {
                    min_self(ans[k], clamp(le, l[k], r[k]));
                }
                if(ri!=-1) {
                    min_self(ans[k], clamp(ri, l[k], r[k]));
                }
                le = ans[k];
            }
        }
        i = j;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}