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

struct AhoCorasick {
    enum {alpha = 26, first = 'a'}; // change this!
    struct Node {
        // (nmatches is optional)
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
    vector<Node> N;
    vi backp;
    void insert(string& s, int j) {
        assert(!s.empty());
        int n = 0;
        for (char c : s) {
            int& m = N[n].next[c - first];
            if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
            else n = m;
        }
        if (N[n].end == -1) N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
    }
    AhoCorasick(vector<string>& pat) : N(1, -1) {
        rep(i,0,sz(pat)) insert(pat[i], i);
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
    }
    vi find(string word) {
        int n = 0;
        vi res; // ll count = 0;
        for (char c : word) {
            n = N[n].next[c - first];
            res.push_back(N[n].end);
            // count += N[n].nmatches;
        }
        return res;
    }
    vector<vi> findAll(vector<string>& pat, string word) {
        vi r = find(word);
        vector<vi> res(sz(word));
        rep(i,0,sz(word)) {
            int ind = r[i];
            while (ind != -1) {
                res[i - sz(pat[ind]) + 1].push_back(ind);
                ind = backp[ind];
            }
        }
        return res;
    }
};

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<H> wh;
        rep(i,0,sz(words)) {
            wh.push_back(hashString(words[i]));
        }
        map<ull,pii> mp;
        rep(i,0,sz(words)) {
            ull hs = wh[i].get();
            if(mp.count(hs)) {
                min_self(mp[hs], (pii){costs[i],i});
            } else {
                mp[hs] = {costs[i],i};  
            }
        }
        vector<string> w2;
        map<int,int> w2cost;
        for(auto [hsi, cid]: mp) {
            auto [c, id] = cid;
            w2cost[sz(w2)] = c;
            w2.push_back(words[id]);
        }
        AhoCorasick ac(w2);
        auto res = ac.findAll(w2, target);
        vector<int> dp(sz(target)+1, 1e9);
        dp[0] = 0;
        rep(i,0,sz(target)) {
            for(int id: res[i]) {
                int len = sz(w2[id]);
                min_self(dp[i+len], dp[i]+w2cost[id]);
            }
        }
        if(dp[sz(target)]==1e9) {
            return -1;
        } else {
            return dp[sz(target)];
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}