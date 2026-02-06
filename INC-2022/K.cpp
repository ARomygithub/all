#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n;
int a[mxn+1],ans[mxn+1];

const int N = 1e5 + 9;

int t[N][18];
void build(int n) {
  for(int i = 1; i <= n; ++i) t[i][0] = ans[i];
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = max(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return max(t[l][k], t[r - (1 << k) + 1][k]);
}

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    vector<int> af(n+1,-1);
    vector<int> bf(n+1,-1);
    int r=-1;
    for(int i=n;i>0;i--) {
        if(a[i]==-1) {
            if(r==-1) {
                r = i;
            } else {
                af[r] = i;
                bf[i] = r;
                r = i;
            }
        } else {
            if(bf[a[i]]==-1) {
                bf[a[i]] = i;
                af[i] = a[i];
            } else {
                int b = bf[a[i]];
                af[b] = i;
                bf[i] = b;
                af[i] = a[i];
                bf[a[i]] = i; 
            }
        }
    }
    vector<int> v;
    v.push_back(1);
    int u=1;
    while(bf[u]!=-1) {
        v.push_back(bf[u]);
        u = bf[u];
    }
    reverse(v.begin(),v.end());
    u = 1;
    while(af[u]!=-1) {
        v.push_back(af[u]);
        u = af[u];
    }
    if(sz(v)!=n) {
        cout <<"-1\n";
    } else {
        for(int i=0;i<n;i++) {
            ans[v[i]] = i+1;
        }
        build(n);
        for(int i=1;i<=n;i++) {
            if(a[i]==-1) {
                if(!(ans[i]>=query(i,n))) {
                    cout <<"-1\n";
                    return;
                }
            } else {
                if(!(ans[i]>=query(i,a[i]-1))) {
                    cout <<"-1\n";
                    return;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(i==1) {
                cout <<ans[i];
            } else {
                cout <<" " <<ans[i];
            }
        }
        cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}