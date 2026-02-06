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

const int mxn=1e5,mxa=1e6;
int n,t;
vi fp;

void solve() {
    cin >>n;
    string ans = "";
    vector<pii> v;
    while(n>1) {
        int fpi = fp[n];
        int ct = 0;
        while((n%fpi)==0) {
            ct++;
            n /=fpi;
        }
        v.push_back({fpi,ct});
    }
    rep(i,0,sz(v)) {
        auto [fpi, ct] = v[i];
        if(ct==1) {
            ans +=to_string(fpi);
        } else {
            ans +=to_string(fpi)+"^"+to_string(ct);
        }
        if(i<sz(v)-1) {
            ans += " x ";
        }
    }
    cout <<ans <<"\n";
}

void init() {
    fp.resize(mxa+1,mxa);
    vector<bool> isComp(mxa+1, 0);
    rep(i,2,mxa+1) {
        if(!isComp[i]) {
            min_self(fp[i], i);
            for(ll j=i*2;j<=mxa;j+=i) {
                isComp[j] = 1;
                min_self(fp[j], i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}