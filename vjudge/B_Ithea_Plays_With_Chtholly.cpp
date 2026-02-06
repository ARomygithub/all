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

const int mxn=1e5;
int n,m,c;

void solve() {
    cin >>n >>m >>c;
    int l = 0, r = 0;
    vi vl,vr;
    rep(i,0,m) {
        int cur; cin >> cur;
        if(cur <= (c/2)) {
            auto it = upper_bound(all(vl), cur);
            if(it==vl.end()) {
                vl.push_back(cur);
                l++;
                cout <<l <<"\n" <<flush;
            } else {
                cout <<(it-vl.begin())+1 <<"\n" <<flush;
                *it = cur;
            }
        } else {
            auto it = upper_bound(all(vr),-cur);
            if(it==vr.end()) {
                vr.push_back(-cur);
                r++;
                cout <<n-r+1 <<"\n" <<flush;
            } else {
                cout <<(n - (it-vr.begin())) <<"\n" <<flush;
                *it = -cur;
            }
        }
        if(l+r>=n) exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}