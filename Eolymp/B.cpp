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
ll a,b;
int g;

void solve() {
    cin >>a >>b >>g;
    ll ans1=0,ans2=-1;
    ll bth = a-b;
    if(bth>=0 && (bth|b)==b) {
        ans1 = 1;
        ll ct = 0;
        if((b^bth)>0) {
            ct = __builtin_popcountll(b^bth);
        }
        ans1 = 1ll<<ct;
        ll x = b^bth;
        ans2 = 0;
        per(i,60,-1) {
            if((x>>(i*1ll))&1) {
                ll p2 = 1ll<<i;
                ans2 = p2 - (x-p2);
                break;
            }
        }
    }
    if(g) {
        cout <<ans1 <<"\n";
        cout <<ans2 <<"\n";
    } else {
        cout <<ans1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}