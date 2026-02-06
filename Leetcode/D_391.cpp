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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int ans = 2e9;
        set<pii> s01,s02;
        vector<pii> ps(sz(points));
        rep(i,0,sz(points)) {
            ps[i] = {points[i][0],points[i][1]};
        }
        sort(ps.begin(),ps.end());
        s01.insert({ps[0].fi - ps[0].se,0});
        s02.insert({(ps[0].fi+ps[0].se),0});
        pii lr;
        int lrv = 0;
        rep(i,1,sz(ps)) {
            int t1 = ps[i].fi-ps[i].se - (*s01.begin()).fi;
            int t2 = ps[i].fi+ps[i].se - (*s02.begin()).fi;
            if(t1>=t2) {
                if(t1>lrv) {
                    lrv = t1;
                    lr = {(*s01.begin()).se,i};
                }
            }  else {
                if(t2>lrv) {
                    lrv = t2;
                    lr = {(*s02.begin()).se,i};
                }
            }
            s01.insert({ps[i].fi-ps[i].se,i});
            s02.insert({ps[i].fi+ps[i].se,i});
        }
        s01.clear(); s02.clear();
        lrv = 0;
        rep(i,0,sz(ps)) {
            if(sz(s01)==0) {
                if(i!=lr.fi) {
                    s01.insert({ps[i].fi-ps[i].se,i});
                    s02.insert({ps[i].fi+ps[i].se,i});
                }
                continue;
            }
            if(i==lr.fi) continue;
            int t1 = ps[i].fi-ps[i].se - (*s01.begin()).fi;
            int t2 = ps[i].fi+ps[i].se - (*s02.begin()).fi;
            if(t1>=t2) {
                if(t1>lrv) {
                    lrv = t1;
                }
            }  else {
                if(t2>lrv) {
                    lrv = t2;
                }
            }
            s01.insert({ps[i].fi-ps[i].se,i});
            s02.insert({ps[i].fi+ps[i].se,i});
        }        
        min_self(ans, lrv);
        s01.clear(); s02.clear();
        lrv = 0;
        rep(i,0,sz(ps)) {
            if(sz(s01)==0) {
                if(i!=lr.se) {
                    s01.insert({ps[i].fi-ps[i].se,i});
                    s02.insert({ps[i].fi+ps[i].se,i});
                }
                continue;
            }
            if(i==lr.se) continue;
            int t1 = ps[i].fi-ps[i].se - (*s01.begin()).fi;
            int t2 = ps[i].fi+ps[i].se - (*s02.begin()).fi;
            if(t1>=t2) {
                if(t1>lrv) {
                    lrv = t1;
                }
            }  else {
                if(t2>lrv) {
                    lrv = t2;
                }
            }
            s01.insert({ps[i].fi-ps[i].se,i});
            s02.insert({ps[i].fi+ps[i].se,i});
        }        
        min_self(ans, lrv);   
        return ans;     
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector poin(6, vector<int>());
    poin[0] = vector<int>({5,3});
    poin[1] = vector<int>({4,6});
    poin[2] = vector<int>({2,4});
    poin[3] = vector<int>({1,8});
    poin[4] = vector<int>({3,9});
    poin[5] = vector<int>({1,6});
    cout <<sol.minimumDistance(poin);
}