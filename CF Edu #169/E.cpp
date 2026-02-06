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

const int mxn=3e5,mxa=1e7;
int n,t;
int a[mxn];
vi fp;
map<int,int> mp;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int xr = 0;
    rep(i,0,n) {
        if(a[i]%2) {
            if(a[i]>1) {
                xr ^= mp[fp[a[i]]];
            } else {
                xr ^=1;
            }
        }
    }
    if(xr) {
        cout <<"Alice\n";
    } else {
        cout <<"Bob\n";
    }
}

void init() {
    fp.resize(mxa+1,mxa);
    int id = 1;
    mp[1] = id; id++;
    vector<bool> isComp(mxa+1,0);
    rep(i,2,mxa+1) {
        if(!isComp[i]) {
            fp[i] = i;
            if(i>2) {
                mp[i] = id; id++;
            }
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
    init();
    cin >>t;
    while(t--) {
        solve();
    }
}