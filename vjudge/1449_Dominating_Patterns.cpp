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

const int mxn=1e5;
int n,t;

#define tcT template<class T
tcT> using V = vector<T>; 

using str = string;
using vl = vector<ll>;

#define pb push_back
#define eb emplace_back
#define each(a,x) for(auto& a: x)
#define rsz resize

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)

struct SuffixAutomaton {
    int N = 1; vi lnk{-1}, len{0}, pos{-1}; // suffix link, 
    // max length of state, last pos of first occurrence of state
    V<map<char,int>> nex{1}; V<bool> isClone{0};
    // transitions, cloned -> not terminal state
    V<vi> iLnk; // inverse links
    int add(int p, char c) { // ~p nonzero if p != -1
        auto getNex = [&]() {
            if (p == -1) return 0;
            int q = nex[p][c]; if (len[p]+1 == len[q]) return q;
            int clone = N++; lnk.pb(lnk[q]); lnk[q] = clone;
            len.pb(len[p]+1), nex.pb(nex[q]),
            pos.pb(pos[q]), isClone.pb(1);
            for (; ~p && nex[p][c] == q; p = lnk[p]) nex[p][c]=clone;
            return clone;
        };
        // if (nex[p].count(c)) return getNex();
        // ^ need if adding > 1 string
        int cur = N++; // make new state
        lnk.eb(), len.pb(len[p]+1), nex.eb(),
        pos.pb(pos[p]+1), isClone.pb(0);
        for (; ~p && !nex[p].count(c); p = lnk[p]) nex[p][c] = cur;
        int x = getNex(); lnk[cur] = x; return cur;
    }
    void init(str s) { int p = 0; each(x,s) p = add(p,x); } /// add string to automaton
    // inverse links
    void genIlnk() {iLnk.rsz(N);rep(v,1,N)iLnk[lnk[v]].pb(v);}
    // APPLICATIONS
    void getAllOccur(vi& oc, int v) {
        if (!isClone[v]) oc.pb(pos[v]); // terminal position
        each(u,iLnk[v]) getAllOccur(oc,u); }
    int allOccur(str s) { // get all occurrences of s in automaton
        int cur = 0;
        each(x,s) {
            if (!nex[cur].count(x)) return {};
            cur = nex[cur][x]; }
        // convert end pos -> start pos
        vi oc; getAllOccur(oc,cur);
        // each(t,oc) t += 1-sz(s);
        // sort(all(oc)); return oc;
        return sz(oc);
    }
    vl distinct;
    ll getDistinct(int x) {
        // # distinct strings starting at state x
        if (distinct[x]) return distinct[x];
        distinct[x]=1;each(y,nex[x]) distinct[x]+=getDistinct(y.se);
        return distinct[x]; }
    ll numDistinct() { // # distinct substrings including empty
        distinct.rsz(N); return getDistinct(0); }
    ll numDistinct2() { // assert(numDistinct()==numDistinct2());
        ll ans = 1; rep(i,1,N) ans += len[i]-len[lnk[i]];
        return ans; } 
};

void solve() {
    cin >>n;
    if(n==0) {
        exit(0);
    }
    vector<string> vs(n);
    rep(i,0,n) {
        cin >>vs[i];
    }
    vi ans;
    int ct = 0;
    string s; cin >>s;
    SuffixAutomaton dfa;
    dfa.init(s);
    dfa.genIlnk();
    rep(i,0,n) {
        // cout <<i <<endl;
        int cur = dfa.allOccur(vs[i]);
        if(cur>ct) {
            ans.clear();
            ct = cur;
            ans.push_back(i);
        } else if(cur==ct) {
            ans.push_back(i);
        }
    }
    cout <<ct <<"\n";
    for(auto id: ans) {
        cout <<vs[id] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        solve();
    }
}