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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=(1<<20);
int h,g,t;
int a[mxn*2];

bool cancel(int u) {
    bool revert = 0;
    int tmp = a[u];
    if(a[u*2]==0 && a[u*2+1]==0) {
        a[u] = 0;
        if(u<(1<<g)) {
            revert = 1;
        }
    } else {
        if(a[u*2]>a[u*2+1]) {
            a[u] = a[u*2];
            revert = !cancel(u*2);
        } else {
            a[u] = a[u*2+1];
            revert = !cancel(u*2+1);
        }
    }
    if(revert) {
        a[u] = tmp;
    }
    return !revert;
}

void solve() {
    cin >>h >>g;
    rep(i,1,(1<<h)) {
        cin >>a[i];
    }
    ll s = 0;
    vector<int> ans;
    rep(i,1,(1<<g)) {
        while(cancel(i)) {
            ans.push_back(i);
        }
        s += a[i];
    }
    cout <<s <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
    rep(i,1,(1<<h)) {
        a[i] = 0;
    }
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