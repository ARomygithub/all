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
int n,m,t;
string s;
int a[mxn];

void solve() {
    cin >>n >>m;
    cin >>s;
    rep(i,0,m) {
        cin >>a[i];
    }
    int cur = 1;
    vi ans;
    int id = 0;
    if(a[id]==cur) {
        ans.push_back(cur);
        id++;
    }
    rep(i,0,n) {
        if(s[i]=='A') {
            cur++;
            if(id<m && a[id]==cur) {
                id++;
            }
        } else {
            while(id<m && a[id]==cur+1) {
                cur++;
                ans.push_back(a[id]);
                id++;
            }
            cur++;
        }
        ans.push_back(cur);
        if(s[i]=='B') {
            while(id<m && a[id]==cur+1) {
                cur++;
                ans.push_back(a[id]);
                id++;
            }
            cur++;            
        }
    }
    while(id<m) {
        ans.push_back(a[id]);
        id++;
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
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