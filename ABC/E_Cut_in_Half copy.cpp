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
int n,k,x,t;
int a[mxn];

void solve() {
    cin >>n >>k >>x;
    rep(i,0,n) {
        cin >>a[i];
    }
    map<double,int> mp;
    sort(a,a+n);
    rep(i,0,n) {
        double ats = a[i];
        rep(j,0,31) {
            if(j>0) {
                ats /= 2.0;
            }
            mp[ats] = 1;
            if(ats*(1<<30) < a[n-1]) break;
        }
    }
    vector<double> v;
    for(auto [val,ke]: mp) {
        v.push_back(val);
    }
    sort(all(v));
    vi ct(sz(v), 0);
    rep(i,0,sz(v)) {
        mp[v[i]] = i;
    }
    rep(i,0,n) {
        int id = mp[1.0*a[i]];
        ct[id]++;
    }
    per(i,sz(v)-1,0) {
        if(ct[i]) {
            int tmp = min(ct[i], k);
            ct[i] -= tmp;
            k -= tmp;
            int j = mp[v[i]/2.0];
            ct[j] += tmp*2;
            if(k<=0) break;
        }
    }
    per(i,sz(v)-1,-1) {
        if(ct[i]) {
            x -= ct[i];
            if(x<=0) {
                cout <<fixed <<setprecision(11) <<v[i] <<"\n";
                return;
            }
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