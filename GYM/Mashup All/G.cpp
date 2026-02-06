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

const int mxn=2e5,mxs=1+(int)(4e5);
int n;

struct Val {
    vi a[mxs];
    ll calc(int md) {
        vi pn(mxs,mxn), px(mxs,-mxn), sn(mxs,mxn), sx(mxs,-mxn);
        rep(i,1,mxs) {
            pn[i] = pn[i-1];
            px[i] = px[i-1];
            for(auto ai : a[i]) {
                min_self(pn[i], ai);
                max_self(px[i],ai);
            }
        }
        per(i,mxs-2,-1) {
            sn[i] = sn[i+1];
            sx[i] = sx[i+1];
            for(auto ai: a[i]) {
                min_self(sn[i], ai);
                max_self(sx[i], ai);
            }
        }
        ll ret = 0;
        rep(x,0,mxs) {
            if((x%2)!=md) continue;
            int l = max(pn[x-1],sn[x+1])+1;
            int r = min(px[x-1],sx[x+1])-1;
            if((l-x+mxs-1)%2) {
                l++;
            }
            if((r-x+mxs-1)%2) {
                r--;
            }
            if(l<=r) {
                // cout <<l <<" " <<r <<" " <<x <<endl;
                int ad = (r-l+1)/2 +1;
                ret += ad;
            }
        }
        return ret;
    }
};

Val v[2];

void solve() {
    cin >>n;
    ll ans = 0;
    rep(i,0,n) {
        int x,y; cin >>x >>y;
        v[(x+y+mxn)%2].a[(x+y+mxn)].push_back(x-y);
    }
    ans += v[0].calc(1);
    ans += v[1].calc(0);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}