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

const int mxn=1e5;
int n;

void ask2(int a1, int a2) {
    cout <<"2 " <<a1 <<" " <<a2 <<"\n";
    cout <<flush;
}

vector<int> ask(vector<int>& v) {
    cout <<sz(v) <<" ";
    cout <<flush;
    rep(i,0,sz(v)) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
    cout <<flush;
    vector<int> retu;
    int start; cin >>start;
    rep(i,0,sz(v)) {
        retu.push_back(start+i>n?start+i-n:start+i);
    }
    return retu;
}

void solve() {
    cin >>n;
    if(n<=3) {
        cout <<"0\n";
        cout <<flush;
        return;
    }
    pii best{-1,-1};
    rep(k,2,n) {
        pii cur = {n-k-(n+k-1)/k + 1, k};
        max_self(best, cur);
    }
    // cout <<best.fi <<" " <<best.se <<"\n";
    int k = best.se;
    set<int> spec;
    for(int i=1;i<=n;i+=k) {
        spec.insert(i);
    }
    vector<bool> on(n+1,0);
    while(true) {
        vector<int> gather;
        rep(i,1,n+1) {
            if(!on[i] && !spec.count(i)) {
                gather.push_back(i);
                if(sz(gather)==k) break;
            }
        }
        rep(i,0,sz(gather)) {
            on[gather[i]] = 1;
        }
        auto ers = ask(gather);
        rep(i,0,sz(ers)) {
            on[ers[i]] = 0;
        }
        int ct1 = 0;
        rep(i,1,n+1) {
            ct1 += on[i];
        }
        if(ct1>=best.fi) {
            cout <<"0\n";
            cout <<flush;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}