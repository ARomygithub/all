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

const int mxn=2e5;
int n,q;
int a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector id(mxn+1,vi());
    rep(i,0,n) {
        id[a[i]].push_back(i);
    }
    vi r(n);
    iota(all(r),0);
    rep(i,0,mxn+1) {
        rep(j,0,sz(id[i])-1) {
            r[id[i][j]] = id[i][j+1];
        }
    }
    // int blok = 0;
    int ans = 0;
    for(int i=0;i<n;) {
        map<int,int> mp;
        int ri = r[i];
        mp[a[i]]++;
        int j=i+1;
        while(j<=ri) {
            mp[a[j]]++;
            max_self(ri, r[j]);
            j++;
        }
        int dom = 0;
        for(auto [k,v]: mp) {
            max_self(dom, v);
        }
        ans += (j-i)-dom;
        // blok++;
        i = j;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}