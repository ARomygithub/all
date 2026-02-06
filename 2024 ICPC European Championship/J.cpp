#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
typedef pair<pii,pii> pipi;
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=50;
const int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};
int r,c;
string s[mxn], t[mxn];

bool e(int i, int j) {
    return i>=0&&i<r&&j>=0&&j<c;
}

void create_graph(set<ipii>& cand, pii cur, pii nxt, map<pii,int>& mps, set<pii>& udh) {
    vector<string> g(r);
    rep(i,0,r) {
        g[i] = "";
        rep(j,0,c) {
            if(cand.count({mps[{i,j}],{i,j}})) {
                g[i] += '*';
            } else if(udh.count({i,j})) {
                g[i] += 'U';
            } else if(s[i][j]=='X') {
                g[i] += 'X';
            } else {
                g[i] += '.';
            }
        }
        cout <<g[i] <<endl;
    }
    cout <<endl;
    g[cur.fi][cur.se] = 'A';
    g[nxt.fi][nxt.se] = 'N';
    rep(i,0,r) {
        cout <<g[i] <<endl;
    }
}

void solve() {
    cin >>r >>c;
    rep(i,0,r) {
        cin >>s[i];
    }
    rep(i,0,r) {
        cin >>t[i];
    }
    set<pii> cs, cf;
    map<pii,int> mps;
    rep(i,0,r) {
        rep(j,0,c) {
            if(s[i][j]=='*') {
                cs.insert({i,j});
                rep(k,0,4) {
                    int ii = i+di[k], jj=j+dj[k];
                    if(e(ii,jj) && s[ii][jj]=='*') {
                        mps[{i,j}]++;
                    }
                }
            }
        }
    }
    rep(i,0,r) {
        rep(j,0,c) {
            if(t[i][j]=='*') {
                cf.insert({i,j});
            }
        }
    }
    // int ct = sz(cf);
    set<pii> udh;
    for(auto [i,j]: cf) {
        if(cs.count({i,j})) {
            udh.insert({i,j});
            break;
        }
    }
    if(sz(udh)) {
        cs.erase(*udh.begin());
    }
    set<ipii> cand;
    for(auto [i,j]: cs) {
        cand.insert({mps[{i,j}],{i,j}});
    }
    vector<pipi> ans;
    if(!sz(udh)) {
        vector dp(r, vector<int>(c, 1e9));
        vector p(r, vector<pii>(c, {-1,-1}));
        priority_queue<ipii, vector<ipii>, greater<ipii>> pq;
        for(auto [i,j]: cs) {
            dp[i][j] = 0;
            pq.push({0,{i,j}});
        }
        while(sz(pq)) {
            auto [w,ij] = pq.top(); pq.pop();
            auto [i,j] = ij;
            if(dp[i][j]<w) continue;
            if(cf.count({i,j})) {
                vector<pii> path;
                udh.insert({i,j});
                while(p[i][j].fi !=-1) {
                    path.push_back({i,j});
                    pii temp = p[i][j];
                    i = temp.fi;
                    j = temp.se;
                }
                path.push_back({i,j});
                per(id,sz(path)-1,0) {
                    pii cur = path[id];
                    pii nxt = path[id-1];
                    cand.erase({mps[cur],cur});
                    auto [mpa, apus] = *cand.begin();
                    cand.erase(cand.begin());
                    rep(k,0,4) {
                        pii adj = {cur.fi+di[k],cur.se+dj[k]};
                        if(cand.count({mps[adj],adj})) {
                            cand.erase({mps[adj],adj});
                            mps[adj]--;
                            cand.insert({mps[adj],adj});
                        }
                    }                    
                    ans.push_back({apus, nxt});
                    mps[apus] = 0;
                    rep(k,0,4) {
                        pii adj = {apus.fi+di[k],apus.se+dj[k]};
                        if(cand.count({mps[adj],adj})) {
                            cand.erase({mps[adj],adj});
                            mps[adj]--;
                            assert(mps[adj]>0);
                            cand.insert({mps[adj],adj});
                        }
                    }
                    auto add = [&](pii added) -> void {
                        mps[added] = 0;
                        rep(k,0,4) {
                            pii adj = {added.fi+di[k], added.se+dj[k]};
                            if(cand.count({mps[adj],adj})) {
                                mps[added]++;
                                cand.erase({mps[adj],adj});
                                mps[adj]++;
                                cand.insert({mps[adj],adj});
                            }
                        }
                        // if(mps[added]==0) {
                            // debug() <<imie(cur) <<imie(nxt);
                            // debug() <<imie(mps);
                            // debug() <<imie(added);
                            // create_graph(cand, cur, nxt, mps);
                            // debug() <<imie(path);
                        // }
                        assert(mps[added]>0);
                        cand.insert({mps[added],added});
                    };
                    add(cur);
                    add(nxt);
                }
                cand.erase({mps[path[0]],path[0]});
                break;
            }
            rep(k,0,4) {
                int ii = i+di[k], jj=j+dj[k];
                if(e(ii,jj) && dp[ii][jj]>w+1 && s[ii][jj]!='X') {
                    dp[ii][jj] = w+1;
                    p[ii][jj] = {i,j};
                    pq.push({w+1,{ii,jj}});
                }
            }
        }
    }
    // cout <<sz(ans) <<"\n";
    // rep(i,0,sz(ans)) {
    //     cout <<ans[i].fi.fi+1 <<" " <<ans[i].fi.se+1 <<" " <<ans[i].se.fi+1 <<" " <<ans[i].se.se+1 <<"\n";
    // }    
    queue<pii> que;
    if(!sz(udh)) {
        cout <<"NO\n";
        return;
    }
    map<pii, int> ord;
    vector vis(r, vector<bool>(c,0));
    function<void(pii)> dfs;
    int ord_id = 0;
    dfs = [&](pii u) -> void {
        vis[u.fi][u.se] = 1;
        rep(k,0,4) {
            pii adj = {u.fi+di[k], u.se+dj[k]};
            if(cand.count({mps[adj],adj}) && !vis[adj.fi][adj.se]) {
                dfs(adj);
            }
        }
        if(u != (*udh.begin())) {
            ord[u] = ord_id++;
            cand.erase({mps[u],u});
            cand.insert({ord[u],u});
        }
    };
    dfs(*udh.begin());
    que.push(*udh.begin());
    while(sz(que)) {
        auto cur = que.front(); que.pop();
        rep(k,0,4) {
            pii nxt = {cur.fi+di[k], cur.se+dj[k]};
            if((!udh.count(nxt)) && cf.count(nxt)) {
                if(cand.count({ord[nxt],nxt})) {
                    udh.insert(nxt);
                    cand.erase({ord[nxt],nxt});
                } else {
                    auto it = cand.begin();
                    auto [mpa, apus] = *it;
                    // create_graph(cand, apus, nxt, ord, udh);
                    // cout <<endl;
                    cand.erase(it);
                    ans.push_back({apus, nxt});
                    // rep(k2,0,4) {
                    //     pii adj = {apus.fi+di[k2], apus.se+dj[k2]};
                    //     if(cand.count({mps[adj],adj})) {
                    //         cand.erase({mps[adj],adj});
                    //         mps[adj]--;
                    //         assert(mps[adj]>0);
                    //         cand.insert({mps[adj],adj});
                    //     }
                    // }
                    // rep(k2,0,4) {
                    //     pii adj = {nxt.fi+di[k2],nxt.se+dj[k2]};
                    //     if(cand.count({mps[adj],adj})) {
                    //         cand.erase({mps[adj],adj});
                    //         mps[adj]++;
                    //         cand.insert({mps[adj],adj});
                    //     }
                    // }
                    udh.insert(nxt);
                }
                que.push(nxt);
            }
        }
    }
    cout <<"YES\n";
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi.fi+1 <<" " <<ans[i].fi.se+1 <<" " <<ans[i].se.fi+1 <<" " <<ans[i].se.se+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}