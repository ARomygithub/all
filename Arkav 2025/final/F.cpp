#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=2e5,mxb=20;
int n,q;
int tr[1<<(mxb+1)],ar[mxn];

void add(int ind, int end) { 
    int u = (1<<mxb)+ar[ind];
    while(u) {
        tr[u]++;
        u /= 2;
    }
} // add ar[ind] (end = 0 or 1)
void del(int ind, int end) { 
    int u = (1<<mxb)+ar[ind];
    while(u) {
        tr[u]--;
        u /= 2;
    }
} // remove ar[ind]
int calc(int ki, int xi) { 
    // cout <<"calc" <<endl;
    int u = 1;
    int ret = 0;
    per(j,19,-1) {
        int cur = (xi>>j)&1;
        int u1 = u*2+cur, u2 = u*2+(1-cur);
        if(tr[u1]<ki) {
            ki -= tr[u1];
            u = u2;
            ret += (1<<j);
        } else {
            u = u1;
        }
    }
    return ret;
} // compute current answer

vi moTree(vector<array<int, 4>> Q, vector<vi>& ed, int root=0){
	int N = sz(ed), pos[2] = {}, blk = 350; // ~N/sqrt(Q)
	vi s(sz(Q)), res = s, I(N), L(N), R(N), in(N), par(N);
	add(0, 0), in[0] = 1;
	auto dfs = [&](int x, int p, int dep, auto& f) -> void {
		par[x] = p;
		L[x] = N;
		if (dep) I[x] = N++;
		for (int y : ed[x]) if (y != p) f(y, x, !dep, f);
		if (!dep) I[x] = N++;
		R[x] = N;
	};
	dfs(root, -1, 0, dfs);
#define K(x) pii(I[x[0]] / blk, I[x[1]] ^ -(I[x[0]] / blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) rep(end,0,2) {
		int &a = pos[end], b = Q[qi][end], i = 0;
#define step(c) { if (in[c]) { del(a, end); in[a] = 0; } \
                  else { add(c, end); in[c] = 1; } a = c; }
		// debug() <<imie(a) imie(b) imie(i);
        while (!(L[b] <= L[a] && R[a] <= R[b])) {
            // debug() <<imie(i) imie(b);
            I[i++] = b, b = par[b];
            // debug() <<imie(i) imie(b);
        }
        // cout <<"92" <<endl;
		while (a != b) {
            // debug() <<imie(a);
            // debug() <<imie(par[a]);
            step(par[a]);
        }
        // cout <<"94" <<endl;
		while (i--) step(I[i]);
        // cout <<"96" <<endl;
		if (end) res[qi] = calc(Q[qi][2],Q[qi][3]);
	}
	return res;
}


void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>ar[i];
    }
    vector ed(n, vi());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    cin >>q;
    vector que(q, array<int,4>());
    rep(i,0,q) {
        cin >>que[i][0] >>que[i][1] >>que[i][2] >>que[i][3]; que[i][0]--,que[i][1]--;
    }
    // cout <<"tes" <<endl;
    auto ret = moTree(que, ed);
    rep(i,0,q) {
        cout <<ret[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}