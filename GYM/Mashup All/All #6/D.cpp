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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m,awl;
vi adj[mxn],adj2[mxn];

void solve() {
    cin >>n >>m;
    vector sout(n, set<int>());
    rep(i,0,n) {
        int k; cin >>k;
        rep(j,0,k) {
            int v; cin >>v; v--;
            adj[i].push_back(v);
            adj2[v].push_back(i);
            sout[i].insert(v);
        }
    }
    cin >>awl; awl--;
    vi dp(n,-1);
    queue<int> q;
    vector<bool> udh(n,0);
    rep(i,0,n) {
        if(sz(sout[i])==0) {
            q.push(i);
            // udhq[i] = 1;
        }
    }
    while(sz(q)) {
        auto u = q.front(); q.pop();
        debug() <<"que " <<imie(u); 
        if(udh[u]) continue;
        udh[u] = 1;
        if(sz(adj[u])) {
            bool an1 = 0;
            bool a0 = 0;
            for(int v: adj[u]) {
                an1 = an1 || dp[v]==-1;
                a0 = a0 || dp[v]==0;
            }
            if(an1) {
                dp[u] = 1;
            } else if(a0) {
                dp[u] = 0;
            } else {
                dp[u] = -1;
            }
        } else {
            dp[u] = -1;
        }
        if(dp[u]==-1) {
            for(auto u2: adj2[u]) {
                debug() <<imie(u2);
                dp[u2] = 1;
                udh[u2] = 1;
                for(auto u3: adj2[u2]) {
                    debug() <<imie(u3);
                    sout[u3].erase(u2);
                    if(sz(sout[u3])==0 && !udh[u3]) {
                        q.push(u3);
                    }
                }
            }
        } else {
            for(auto u2: adj2[u]) {
                debug() <<imie(u2);
                sout[u2].erase(u);
                if(sz(sout[u2])==0 && !udh[u2]) {
                    q.push(u2);
                    // udhq[u2] = 1;
                }
            }
        }
    }
    rep(i,0,n) {
        if(!udh[i]) {
            dp[i] = 0;
        }
    }
    debug() <<imie(dp);
    int mx = -1;
    for(int u : adj[awl]) {
        if(sz(adj[u])) {
            for(int v: adj[u]) {
                max_self(mx, dp[v]);
                if(mx==1) {
                    cout <<"Win\n";
                    vi ans;
                    vector<bool> vis(n,0);
                    ans.push_back(awl);
                    vis[awl] = 1;
                    ans.push_back(u);
                    vis[u] = 1;
                    ans.push_back(v);
                    vis[v] = 1;
                    debug() <<imie(ans);
                    int ui = v;
                    while(sz(adj[ui])) {
                        debug() <<imie(ui);
                        if(dp[ui]==1) {
                            int nx = -1;
                            for(int ui2: adj[ui]) {
                                if(dp[ui2]==-1 && !vis[ui2]) {
                                    nx = ui2;
                                    break;
                                }
                            }
                            assert(nx!=-1);
                            ans.push_back(nx);
                            vis[nx] = 1;
                            ui = nx;
                        } else { //-1
                            int nx = -1;
                            for(auto ui2: adj[ui]) {
                                if(!vis[ui2]) {
                                    nx = ui2;
                                    break;
                                }
                            }
                            ui = nx;
                            vis[nx] = 1;
                            ans.push_back(ui);
                        }
                    }
                    rep(i,0,sz(ans)) {
                        cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
                    }
                    return;
                }
            }
        } else {
            cout <<"Win\n";
            cout <<awl+1 <<" " <<u+1 <<"\n";
            return;
        }
    }
    if(mx==0) {
        cout <<"Draw\n";
    } else if(mx==-1) {
        cout <<"Lose\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}