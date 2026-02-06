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

const int mxn=100;
int n;

void solve() {
    cin >>n;
    set<int> s;
    rep(i,0,n) {
        int si; cin >>si;
        s.insert(si);
    }
    vector<string> v;
    int l=-1,r=-1;
    for(auto si: s) {
        if(l==-1) {
            l = si, r= si;
        } else {
            if(si==r+1) {
                r++;
            } else {
                if(l<r) {
                    v.push_back(to_string(l)+"-"+to_string(r));
                } else {
                    v.push_back(to_string(l));
                }
                l = si, r = si;
            }
        }
    }
    if(l<r) {
        v.push_back(to_string(l)+"-"+to_string(r));
    } else {
        v.push_back(to_string(l));
    }    
    rep(i,0,sz(v)) {
        cout <<v[i] <<",\n"[i==sz(v)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}