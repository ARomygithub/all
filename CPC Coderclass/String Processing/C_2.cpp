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

const int mxn=200,mxs=100;
int n,k,l;

struct AhoCorasick {
    vi backp;
    static int alpha;
    struct Node {
        // (nmatches is optional)
        int back, start = -1, end = -1, nmatches = 0;
        int val=0;
        vi next, dp, pari;
        vector<char> parc;
        Node(int v): next(alpha,v), dp(mxn+1, -1), pari(mxn+1,-1), parc(mxn+1,'\0') { }
    };
    vector<Node> N;
    map<char,int> toi, mpr;
    void insert(string& s, int j, int valj) {
        assert(!s.empty());
        int n = 0;
        for (char c : s) {
            int& m = N[n].next[toi[c]];
            if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
            else n = m;
        }
        if (N[n].end == -1) N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
        N[n].val += valj;
        // cout <<"insert" <<endl;
    }
    AhoCorasick(): N(1,-1) {}
    void init(vector<string>& pat, vector<int>& valPat) {
        rep(i,0,sz(pat)) insert(pat[i], i, valPat[i]);
        N[0].back = sz(N);
        N.emplace_back(0);

        queue<int> q;
        for (q.push(0); !q.empty(); q.pop()) {
            int n = q.front(), prev = N[n].back;
            rep(i,0,alpha) {
                int &ed = N[n].next[i], y = N[prev].next[i];
                if (ed == -1) ed = y;
                else {
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
                        = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }

        vector adj(sz(N), vi());
        rep(i,1,sz(N)) {
            int j = N[i].back;
            adj[j].push_back(i);
        }
        function<void(int)> dfs;
        dfs = [&](int u) -> void {
            // cout <<"dfs " <<u <<endl;
            for(int v: adj[u]) {
                N[v].val += N[u].val;
                dfs(v);
            }
        };
        dfs(0);
        // cout <<"Tes" <<endl;
    }
};

int AhoCorasick::alpha;

void solve() {
    cin >>n >>k >>l;
    AhoCorasick::alpha = k;
    AhoCorasick ac;
    vector<string> pat(n);
    vector<int> val(n);
    rep(i,0,n) {
        cin >>pat[i];
        cin >>val[i];
    }
    rep(i,0,k) {
        char c; int rc; cin >>c >>rc;
        ac.toi[c] = i;
        ac.mpr[c] = rc;
    }
    ac.init(pat, val);
    ac.N[0].dp[0] = 0;
    int ans = 0;
    int ans_rest = -1, ans_i=-1;
    rep(rest,0,l+1) {
        rep(i,0,sz(ac.N)) {
            auto& u = ac.N[i];
            if(u.dp[rest]==-1) continue;
            if(u.dp[rest]>ans) {
                ans = u.dp[rest];
                ans_rest = rest;
                ans_i = i;
            } 
            for(auto [c,id]: ac.toi) {
                if(rest+ac.mpr[c]>l) continue;
                int j = u.next[id];
                auto& v = ac.N[j];
                int nrest = rest+ac.mpr[c];
                if(v.dp[nrest]< u.dp[rest]+v.val) {
                    v.dp[nrest] = u.dp[rest]+v.val;
                    v.pari[nrest] = i;
                    v.parc[nrest] = c;
                }
            }
        }
    }
    if(ans) {
        cout <<ans <<"\n";
        string sans = "";
        while(ans_rest>0) {
            auto& u = ac.N[ans_i];
            char c = u.parc[ans_rest];
            ans_i = u.pari[ans_rest];
            ans_rest -= ac.mpr[c];
            sans += c;
        }
        reverse(sans.begin(),sans.end());
        cout <<sans <<"\n";
    } else {
        cout <<"0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}