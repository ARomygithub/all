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

const int mxn=1e5;
int n,k,t;
int a[mxn];

int get_ans() {
    int x = 0;
    rep(i,0,k) {
        max_self(x,a[i]);
    }
    int ct = ((k>0&&x<a[k])?1:0);
    if(x<a[k]) {
        rep(i,k+1,n) {
            if(a[i]<a[k]) {
                ct++;
            } else {
                break;
            }
        }
    }
    return ct;
}

void solve() {
    cin >>n >>k; k--;
    int ka = k;
    int ans = 0;
    rep(i,0,n) {
        cin >>a[i];
    }
    max_self(ans, get_ans());
    swap(a[k],a[0]);
    k = 0;
    max_self(ans, get_ans());
    swap(a[k],a[ka]);
    k = ka;
    int idx = -1;
    rep(i,0,n) {
        if(i==k) continue;
        if(a[i]>a[k]) {
            idx = i;
            break;
        }
    }
    if(idx!=-1) {
        swap(a[k],a[idx]);
        k = idx;
        max_self(ans, get_ans());
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