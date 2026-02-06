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
const ll mod = 998244353;
int n,s,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>s;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    set<int> blm,sisa;
    rep(i,1,n+1) {
        blm.insert(-i);
    }
    rep(i,0,n) {
        if(b[i]!=-1) {
            blm.erase(-b[i]);
        }
        if(b[i]==-1) {
            sisa.insert(-a[i]);
        } else if(a[i]-b[i]>s) {
            cout <<"0\n";
            return;
        }
    }
    auto it = sisa.begin(), it2 = blm.begin();
    ll ans = 1;
    ll cur = 0;
    while(it!=sisa.end()) {
        while(it2!=blm.end() && -(*it) + (*it2)<=s) {
            it2++;
            cur++;
        }
        ans = ans*cur%mod;
        if(cur==0) break;
        cur--;
        it++;
    }
    cout <<ans <<"\n";
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