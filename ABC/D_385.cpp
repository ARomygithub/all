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
int n,m;
ll sx,sy;

set<pll>::iterator addInterval(set<pll>& is, ll L, ll R) {
    if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), before = it;
    while (it != is.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    return is.insert(before, {L,R});
}

void removeInterval(set<pll>& is, ll L, ll R) {
    if (L == R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->second;
    if (it->first == L) is.erase(it);
    else (int&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}

void solve() {
    cin >>n >>m >>sx >>sy;
    map<int,vi> mpx,mpy;
    rep(i,0,n) {
        int x,y; cin >>x >>y;
        mpx[x].push_back(y);
        mpy[y].push_back(x);
    }
    for(auto& [x,vx]: mpx) {
        sort(all(vx));
    }
    for(auto& [y,vy]: mpy) {
        sort(all(vy));
    }
    map<int,set<pll>> isx,isy;
    rep(i,0,m) {
        char d; int c; cin >>d >>c;
        if(d=='U') {
            addInterval(isx[sx], sy, sy+c+1);
            sy += c;
        } else if(d=='D') {
            addInterval(isx[sx], sy-c, sy+1);
            sy -= c;
        } else if(d=='R') {
            addInterval(isy[sy], sx, sx+c+1);
            sx += c;
        } else {
            addInterval(isy[sy], sx-c, sx+1);
            sx -= c;
        }
    }
    set<pii> sh;
    for(auto& [x,sxi]: isx) {
        if(sz(mpx[x])) {
            auto it = sxi.begin();
            auto& vx = mpx[x];
            int id = 0;
            while(id<sz(vx) && it!=sxi.end()) {
                if(vx[id]<it->fi) {
                    id++;
                } else if(vx[id]<it->se) {
                    sh.insert({x,vx[id]});
                    id++;
                } else {
                    it++;
                }
            }
        }
    }
    for(auto& [y,syi]: isy) {
        if(sz(mpy[y])) {
            auto it = syi.begin();
            auto& vy = mpy[y];
            int id = 0;
            while(id<sz(vy) && it!=syi.end()) {
                if(vy[id]<it->fi) {
                    id++;
                } else if(vy[id]<it->se) {
                    sh.insert({vy[id],y});
                    id++;
                } else {
                    it++;
                }
            }            
        }
    }
    cout <<sx <<" " <<sy <<" " <<sz(sh) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}