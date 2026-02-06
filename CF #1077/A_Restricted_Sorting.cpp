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

void solve() {
    cin >>n;
    vi a(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    vi b(a);
    sort(all(b));
    vi c;
    rep(i,0,n) {
        if(a[i]!=b[i]) {
            c.push_back(a[i]);
        }
    } 
    sort(all(c));
    if(sz(c)) {
        int ans = 1;
        int le = 2, ri = 1e9;
        while(le<=ri) {
            int mid = (le+ri)/2;
            int ct = 0;
            ct += sz(c) - (lower_bound(all(c),b[0]+mid)-c.begin());
            ct += upper_bound(all(c),b.back()-mid)-c.begin();
            if(ct>=sz(c)) {
                ans = mid;
                le = mid+1;
            } else {
                ri = mid-1;
            }
        }
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
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