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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,k;
int ct[31+1];

void solve() {
    cin >>n >>k;
    vector<piii> v;
    rep(i,0,n) {
        int a,b; cin >>a >>b;
        v.push_back({{b,a},i});
    }
    vector<int> ans(n);
    sort(v.begin(),v.end());
    rep(i,0,n) {
        rep(j,v[i].fi.se,v[i].fi.fi+1) {
            if(ct[j]<k) {
                ans[v[i].se] = j;
                ct[j]++;
                break;
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}