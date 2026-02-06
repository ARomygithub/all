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
int n,t;
int l[mxn],r[mxn];

void solve() {
    cin >>n;
    vi ct(n*2+1,0);
    rep(i,0,n) {
        cin >>l[i] >>r[i];
    }
    rep(i,0,n) {
        if(l[i]==r[i]) {
            ct[l[i]]++;
        }
    }
    set<int> unik;
    rep(i,1,sz(ct)) {
        if(ct[i]>1) {
            ct[i] = 1;
        } else if(ct[i]==1) {
            ct[i] = 1;
            unik.insert(i);
        }
        ct[i] += ct[i-1];
    }
    rep(i,0,n) {
        if(l[i]==r[i] && unik.count(l[i])) {
            cout <<"1";
            continue;
        }
        int sm = ct[r[i]]-ct[l[i]-1];
        if(sm == r[i]-l[i]+1) {
            cout <<"0";
        } else {
            cout <<"1";
        }
    }
    cout <<"\n";
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