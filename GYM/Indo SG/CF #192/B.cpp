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

const int mxn=1e3;
int n,m;
int ct[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int a,b; cin >>a >>b; a--,b--;
        ct[a]++, ct[b]++;
    }
    vector<pii> ans;
    rep(i,0,n) {
        if(ct[i]==0) {
            rep(j,0,n) {
                if(j!=i) {
                    ans.push_back({i+1,j+1});
                }
            }
            break;
        }
    }
    cout <<sz(ans) <<"\n";
    for(auto [a,b]: ans) {
        cout <<a <<" " <<b <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}