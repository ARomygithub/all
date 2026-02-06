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

const int mxn=1e5,mxe=100;
int n,v[mxn],e[mxn];
vi pr;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>v[i];
    }
    rep(i,0,n) {
        cin >>e[i];
    }
    // cout <<sz(pr) <<"\n";
    // cout <<pr[14] <<"\n";
    vector ct(200,0);
    rep(i,0,n) {
        int cur = (e[i]-1)*2 + v[i];
        ct[cur]++;
    }
    vector vb(15, vector(2, bitset<200>()));
    rep(i,0,15) {
        for(int j=pr[i];j<=mxe;j+=pr[i]) {
            int cur = (j-1)*2;
            vb[i][0].set(cur);
            vb[i][1].set(cur+1);
        }
    }
    int ans = 1e9;
    rep(bit,0,1<<15) {
        bitset<200> bs;
        rep(j,0,15) {
            if((bit>>j)&1) {
                bs |= vb[j][1];
            } else {
                bs |= vb[j][0];
            }
        }
        int temp = 0;
        rep(j,0,200) {
            if(bs[j]) {
                temp += ct[j];
            }
        }
        min_self(ans,temp);
    }
    rep(i,15,sz(pr)) {
        int cur = (pr[i]-1)*2;
        ans += min(ct[cur],ct[cur+1]);
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> isComp(mxe+1,0);
    rep(i,2,mxe+1) {
        if(!isComp[i]) {
            pr.push_back(i);
            for(ll j=i*2;j<=mxe;j+=i) {
                isComp[j] = 1;
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