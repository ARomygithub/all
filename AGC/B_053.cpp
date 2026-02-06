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

const int mxn=2e5;
int n;
ll v[mxn*2];

void solve() {
    cin >>n;
    ll s = 0;
    rep(i,0,n*2) {
        cin >>v[i];
        s += v[i];
    }
    vector<ll> v1,v2;
    per(i,n-1,-1) {
        v1.push_back(v[i]);
    }
    rep(i,n,n*2) {
        v2.push_back(v[i]);
    }
    ll mn = 0;
    multiset<ll> ms;
    per(i,n-1,-1) {
        ms.insert(v1[i]);
        ms.insert(v2[i]);
        ms.erase(--ms.end());
    }
    for(auto msi: ms) {
        mn += msi;
    }
    cout <<s-mn <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}