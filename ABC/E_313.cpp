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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
const ll mod =998244353;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vector<int> veca;
    vector<int> dpna;
    bool ok=1;
    ll ct1 = 0;
    rep(i,0,sz(s)) {
        if(s[i]=='1') {
            ct1++;
        } else {
            veca.push_back(s[i]-'0');
            dpna.push_back(ct1);
            ct1 = 0;
        }
        if(i+1<sz(s)) {
            ok &= (s[i]=='1') || (s[i+1]=='1');
        }
    }
    if(!ok) {
        cout <<"-1\n";
        return;
    }
    ll ans = 0;
    bool adaA = 0;
    per(i,sz(dpna)-1,-1) {
        ans = (ans+ct1)%mod;
        ct1 = 0;
        ll len = i+1+dpna[i];
        if(len<=1) {
            adaA = 1;
            break;
        }
        ans = (ans+1)%mod;
        ct1 = ((ans*(veca[i]-1)%mod) + dpna[i])%mod;
    }
    ll len = ct1 + adaA;
    ans = (ans + len-1)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}