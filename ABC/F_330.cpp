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

const int mxn=2e5;
int n;
ll k;

void solve() {
    cin >>n >>k;
    vector<int> vx(n),vy(n);
    rep(i,0,n) {
        cin >>vx[i] >>vy[i];
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    int lx = 0, rx = n-1;
    int sx = vx[n-1]-vx[0];
    int ctlx = 1, ctrx = 1;
    vector<pii> sumx;
    while(lx<rx) {
        while(lx<rx && vx[lx+1]==vx[lx]) {
            lx++;
            ctlx++;
        }
        while(rx>lx && vx[rx-1]==vx[rx]) {
            rx--;
            ctrx++;
        }
        if(lx==rx) break;
        if(ctlx<=ctrx) {
            sumx.push_back({ctlx,vx[lx+1]-vx[lx]});
            lx++;
            ctlx++;
        } else {
            sumx.push_back({ctrx,vx[rx]-vx[rx-1]});
            rx--;
            ctrx++;
        }
    }
    int ly=0, ry=n-1;
    int sy = vy[n-1]-vy[0];
    int ctly=1, ctry=1;
    vector<pii> sumy;
    while(ly<ry) {
        while(ly<ry && vy[ly+1]==vy[ly]) {
            ly++;
            ctly++;
        }
        while(ly<ry && vy[ry-1]==vy[ry]) {
            ry--;
            ctry++;
        }
        if(ly==ry) break;
        if(ctly<=ctry) {
            sumy.push_back({ctly,vy[ly+1]-vy[ly]});
            ly++;
            ctly++;
        } else {
            sumy.push_back({ctry,vy[ry]-vy[ry-1]});
            ry--;
            ctry++;
        }
    }   
    int l=0,r=max(sx,sy);
    int ans=-1;
    while(l<=r) {
        int mid = (l+r)/2;
        int sxi = sx, syi = sy;
        ll ki = 0;
        rep(i,0,sz(sumx)) {
            if(sxi<=mid) break;
            int temp = min(sumx[i].se,sxi-mid);
            sxi -=temp;
            ki += 1ll*sumx[i].fi*temp;
        }
        rep(i,0,sz(sumy)) {
            if(syi<=mid) break;
            int temp = min(sumy[i].se, syi-mid);
            syi -=temp;
            ki += 1ll*sumy[i].fi*temp;
        }
        if(ki<=k) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}