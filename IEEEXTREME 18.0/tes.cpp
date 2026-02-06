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

const int mxn=1e5,mxa=1e3;
int n;

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vi pr;
    vector<bool> iscomp(mxa+1,0);
    rep(i,2,mxa+1) {
        if(!iscomp[i]) {
            pr.push_back(i);
            for(ll j = i*2;j<=mxa;j+=i) {
                iscomp[j] = 1;
            }
        }
    }
    ll n = 1e14, k = 100;
    cout <<n <<" " <<k <<"\n";
    rep(i,0,k) {
        cout <<pr[i] <<" \n"[i==k-1];
    }
    // cout <<sz(pr);
    // solve();
}