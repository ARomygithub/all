#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

const int mxn = 1e5;
int n;
int a[mxn];

bool cek(vector<ll> x, vector<ll> y) {
    
}

template<class F>
int ternSearch(int le, int ri, F f) {
    assert(le<=ri);
    while(ri-le>=5) {
        int mid = (le+ri)/2;
        if (cek(f(mid), f(mid+1))) le = mid;
        else ri = mid+1;
    }
    rep(i,le+1,ri+1) if(cek(f(le),f(i))) le = i;
    return le;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    vector<string> ans;
    int id = ternSearch(1,n,[&](int i) {
        
        return ;
    });
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}