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
const ll md = 998244353;
int n,a[mxn];
int fp[mxn+1];

ll modpowll(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % md, e /= 2)
		if (e & 1) ans = ans * b % md;
	return ans;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector v(mxn+1, vi());
    rep(i,0,n) {
        int u = a[i];
        while(u>1) {
            int x = fp[u];
            int ct = 0;
            while((u%x)==0) {
                u /= x;
                ct++;
            }
            v[x].push_back(ct);
        }
    }
    // ll tes2 = 0;
    // rep(i,0,sz(v)) {
    //     tes2 += sz(v[i]);
    // }
    // ll tes = 2e6;
    // assert(tes2<=tes);
    ll ans = 1;
    rep(i,0,sz(v)) {
        if(sz(v[i])>1) {
            sort(all(v[i]));
            ll ct = 0;
            rep(j,0,sz(v[i])) {
                ct += v[i][j]*(sz(v[i])-j-1);
            }
            ans = ans*modpowll(i, ct%(md-1))%md;
        }
    }
    cout <<ans <<"\n";
}

void init() {
    bitset<mxn+1> iscomp;
    rep(i,2,mxn+1) {
        if(!iscomp[i]) {
            fp[i] = i;
            for(ll j = 1ll*i*i;j<=mxn+1;j+=i) {
                if(fp[j]==0) {
                    fp[j] = i;
                } else {
                    min_self(fp[j], i);
                }
                iscomp[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}