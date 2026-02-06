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

const int mxn=2e3;
int n;

struct pt {
    ll x, y;
    bool operator < (pt const& t) const {
        return tie(x,y) < tie(t.x,t.y);
    }
};

int orientation(pt a, pt b, pt c) {
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
    reverse(all(a));
}

using P = pt;

void solve() {
    cin >>n;
    vector<P> v(n);
    set<P> ms;
    rep(i,0,n) {
        cin >>v[i].x >>v[i].y;
        ms.insert(v[i]);
    }
    vector<vector<P>> ans;
    while(sz(ms)) {
        vector<P> hull;
        for(auto msi : ms) {
            hull.push_back(msi);
        }
        convex_hull(hull, true);
        for(auto hulli : hull) {
            ms.erase(ms.find(hulli));
        }
        // sz <=2?
        if(sz(hull)<=1) continue;
        // sort(all(hull), [&](P a, P b) ->  bool {
        //     return pii{a.y,a.x}<pii{b.y,b.x};
        // });
        int idx = 0;
        pll yx = {1e18,1e18};
        rep(i,0,sz(hull)) {
            if(pll{hull[i].y,hull[i].x} < yx) {
                idx = i;
                yx = {hull[i].y,hull[i].x};
            }
        }
        if(idx==0) {
            ans.push_back(hull);
        } else {
            vector<P> hullm;
            rep(i,0,sz(hull)) {
                hullm.push_back(hull[(i+idx)%sz(hull)]);
            }
            ans.push_back(hullm);
        }
    }
    rep(i,0,sz(ans)) {
        cout <<"Tembok " <<i+1 <<":\n";
        rep(j,0,sz(ans[i])) {
            cout <<"(" << ans[i][j].x <<", " <<ans[i][j].y <<")" <<"\n";
        }
    }
    // cout <<"tes" <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}