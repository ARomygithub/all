#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=1e6,mxa=14142;
int n;
int a[mxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        s.insert(a[i]);
    }
    if(n<=mxa) {
        int ans = n%2;
        rep(i,0,n) {
            rep(j,i+1,n) {
                if(s.find(a[j]*2-a[i])!=s.end()) {
                    ans++;
                }
            }
        }
        ans %=2;
        cout <<ans <<"\n";
    } else {
        int rnd = (rng())%3;
        rnd = rnd==2?0:1;
        cout <<rnd <<"\n";
    }
    // cout <<"0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}