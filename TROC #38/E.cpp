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
int n,m,d;
int r[mxn],c[mxn];

void solve() {
    cin >>n >>m >>d;
    vector<multiset<int>> vr(2), vc(2);
    n /=2;
    m /=2;
    rep(i,0,d) {
        cin >>r[i] >>c[i];
        vr[r[i]>n].insert(r[i]);
        vc[c[i]>m].insert(c[i]);
    }
    ll ans = 0;
    if(sz(vr[0])>d/2) {
        while(sz(vr[0])>d/2) {
            auto it = --vr[0].end();
            ans += (n+1-(*it));
            vr[0].erase(it);
        }
    } else if(sz(vr[0])<d/2) {
        while(sz(vr[1])>d/2) {
            auto it = vr[1].begin();
            ans += ((*it)-n);
            vr[1].erase(it);
        }
    }
    if(sz(vc[0])>d/2) {
        while(sz(vc[0])>d/2) {
            auto it = --vc[0].end();
            ans += (m+1-(*it));
            vc[0].erase(it);
        }
    } else if(sz(vc[0])<d/2) {
        while(sz(vc[1])>d/2) {
            auto it = vc[1].begin();
            ans += ((*it)-m);
            vc[1].erase(it);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}