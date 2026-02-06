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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    rep(i,0,n-1) {
        if((a[i+1]-a[i])%2) {
            cout <<"-1\n";
            return;
        }
    }
    set<int> s;
    vector<int> v;
    rep(i,0,n) {
        s.insert(a[i]);
    }
    while(!(sz(s)==1 && (*s.begin())==0)) {
        int mid = (*s.begin()) + (*(--s.end()));
        mid /=2;
        v.push_back(mid);
        set<int> s_new;
        for(auto si: s) {
            s_new.insert(abs(mid-si));
        }
        s.swap(s_new);
    }
    cout <<sz(v) <<"\n";
    if(sz(v)==0) {
        cout <<"\n";
    } else {
        rep(i,0,sz(v)) {
            cout <<v[i] <<" \n"[i==sz(v)-1];
        }
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