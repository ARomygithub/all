#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fi first
#define se second

int n,q;
struct FT {
    vector<ll> s;
    FT(int n): s(n) {}
    void update(int pos, ll dif) {
        for(; pos<sz(s); pos |= pos+1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for(; pos>0; pos &= pos-1) res += s[pos-1];
        return res;
    }
};

const ll mod = 1e9+7;
struct node {
    vector<ll> buf;
    node(): buf(6,0) {}
    node(ll p, ll o, ll s): buf(6,0) {
        buf[0] = p;
        buf[3] = o;
        buf[5] = s;
    }
};
struct Tree {
    typedef node T;
    const int id[3][4] = {
        {-1,0,1,2},
        {-1,-1,3,4},
        {-1,-1,-1,5}
    };
    T f(T x, T y) {
        T ret = node();
        rep(i,0,6) {
            ret.buf[i] = (x.buf[i] + y.buf[i])%mod;
        }
        rep(i,0,4) {
            rep(j,i+1,3) {
                rep(k,j+1,4) {
                    ret.buf[id[i][k]] = (ret.buf[id[i][k]] + x.buf[id[i][j]]*y.buf[id[j][k]]%mod)%mod;
                }
            }
        }
        return ret;
    }
    vector<T> s; int n;
    Tree(int n=0): s(2*n, node()), n(n) {}
    void update(int pos, T val) {
        for(s[pos += n]=val; pos /= 2;) {
            // cout <<pos*2 <<" " <<pos*2+1 <<endl;
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }
    T query(int b, int e) {
        T ra = node(), rb = node();
        for(b +=n, e +=n; b<e; b/= 2, e/=2) {
            if(b%2) ra = f(ra,s[b++]);
            if(e%2) rb = f(s[--e],rb);
        }
        // cout <<b <<" " <<e <<endl;
        return f(ra,rb);
    }
};

void solve() {
    cin >> n;
    vi a(n);
    set<int> s;
    rep(i,0,n) {
        cin >>a[i];
        s.insert(a[i]);
    }
    int idi = 0;
    map<int,int> mp;
    while(sz(s)) {
        auto it = s.begin();
        mp[*it] = idi++;
        s.erase(it);
    }
    vector<Tree> vt;
    vector<node> vn(n);
    FT ft(n);
    vector adj(idi, vi());
    rep(i,0,n) {
        adj[mp[a[i]]].push_back(i);
    }
    rep(i,0,idi) {
        for(auto j: adj[i]) {
            ft.update(j,1);
        }
        Tree st(sz(adj[i]));
        for(auto j : adj[i]) {
            ll qry1 = ft.query(j);
            ll qry2 = ft.query(n) - ft.query(j+1);
            vn[j] = node(qry1,1,qry2);
            int pos = lower_bound(all(adj[i]),j)-adj[i].begin();
            st.update(pos,vn[j]);
        }
        vt.push_back(st);
    }
    // cout <<"tes" <<endl;
    cin >>q;
    ll ans = 0;
    rep(i,0,idi) {
        ans = (ans + vt[i].query(0,sz(adj[i])).buf[2])%mod;
    }
    while(q--) {
        int t,x; cin >>t >>x;
        x--;
        int lvl = mp[a[x]];
        ans = (ans - vt[lvl].query(0,sz(adj[lvl])).buf[2] + mod)%mod;
        int pos = lower_bound(all(adj[mp[a[x]]]), x) - adj[mp[a[x]]].begin();
        if(t==0) {
            // cout <<t <<" " <<x <<endl;
            vt[mp[a[x]]].update(pos,node());
        } else {
            vt[mp[a[x]]].update(pos,vn[x]);
        }
        ans = (ans + vt[lvl].query(0,sz(adj[lvl])).buf[2])%mod;
        cout <<ans <<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}