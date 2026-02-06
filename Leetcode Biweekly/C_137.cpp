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

typedef pair<int,pii> ipii;
clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
    //   auto current = chrono::high_resolution_clock::now();
    //   chrono::duration<double> elapsed = current - start;
    //   // cout << fixed << setprecision(3) << elapsed.count() << "\n";
    //   if (elapsed.count() < runtime[i].se) continue;
}

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        cek_time();
        int n = sz(board);
        int m = sz(board[0]);
        vector<ipii> v;
        ll ans = -3e9;
        rep(i,0,n) {
            rep(j,0,m) {
                v.push_back({board[i][j],{i,j}});
            }
        }
        sort(v.begin(),v.end(),greater<ipii>());
        ll tmp0 = 0;
        set<int> sr,sc;
        int yr = -1,xr=-1;
        rep(i,0,sz(v)) {
            auto [val, rc] = v[i];
            auto [r,c] = rc;
            if(!sr.count(r) && !sc.count(c)) {
                tmp0 += val;
                sr.insert(r); sc.insert(c);
                if(sz(sr)==2) {
                    xr = i;
                }
                if(sz(sr)==3) {
                    yr = i;
                    break;
                }
            }
        }
        max_self(ans, tmp0);
        sr.clear(); sc.clear();
        rep(i,0,yr-2) {
            if(1ll*v[i].fi*3 <= ans) break;
            int mulai = i+1;
            if(i==0) {
                mulai = xr+1;
            }
            sr.insert(v[i].se.fi);
            sc.insert(v[i].se.se);
            rep(j,mulai,yr-1) {
                if(1ll*v[i].fi + 1ll*v[j].fi*2 <=ans) break;
                auto [rj, cj] = v[j].se;
                if(sr.count(rj) || sc.count(cj)) continue;
                sr.insert(rj); sc.insert(cj);
                rep(k, j+1,sz(v)) {
                    if(1ll*v[i].fi + v[j].fi + v[k].fi <=ans) break;
                    auto [rk, ck] = v[k].se;
                    if(sr.count(rk) || sc.count(ck)) continue;
                    max_self(ans, 1ll*v[i].fi + v[j].fi + v[k].fi);
                }
                sr.erase(rj); sc.erase(cj);
            }
            sr.erase(v[i].se.fi);
            sc.erase(v[i].se.se);
        }
        cek_time();
        return ans;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=500,m=500;
    vector<vi> board(n, vi(m));
    multiset<int> ms;
    int mxa = 1e9;
    rep(i,0,n) {
        rep(j,0,n) {
            int cur = -mxa + (rng()%(mxa*2+1));
            ms.insert(cur);
        }
    }
    auto it = ms.end();
    rep(i,0,n) {
        rep(j,i,n) {
            it--;
            board[i][j] = *it;
        }
        rep(j,i+1,n) {
            it--;
            board[j][i] = *it;
        }
    }
    Solution sol;
    cout <<sol.maximumValueSum(board) <<"\n";
}