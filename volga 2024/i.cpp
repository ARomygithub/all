// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i--) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string &s, int lim=3) {
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a= sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                s[i + k] == s[j + k]; k++);
    }

};

typedef uint64_t ull;
int C = 998244353;

template<int M, class B>
struct A {
    int x; B b; A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    explicit operator ull() { return x ^ (ull) b << 21; }
    bool operator==(A o) const { return (ull)*this == (ull)o; }
    bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    string s = "";
    vector<HashInterval> vh;
    for (int i = 0; i < n; i++)    
    {
        string s2; cin >> s2;
        HashInterval hai(s2);
        vh.push_back(hai);
        s += s2;
        s += '2';
    }
    // assert('#'>'1');
    rep(i,0,sz(s)) {
        if(s[i]=='1') {
            s[i] = (char)(0);
        } else if(s[i]=='0') {
            s[i] = (char)(1);
        } else {
            s[i] = (char)(2);
        }
    }
    // what_is(s);

    SuffixArray SA(s);
    // RMQ rmq(SA.lcp);
    vector cand(m+1,vector<pii>());
    vi ord(n,-1);
    vector<bool> udh(m+1,0);
    rep(i,1,sz(s)+1) {
        // what_is(i);
        int atlit = (SA.sa[i])/(m+1);
        int r= (SA.sa[i])%(m+1);
        if(r==m) continue;
        int len = m-r;
        if(udh[len]) continue;
        // what_is(SA.sa[i]);
        // what_is(atlit);
        // what_is(r);
        // what_is(len);
        if(len==m) {
            ord[atlit] = sz(cand[len]);
            cand[len].push_back({i,atlit});
        } else {
            if(sz(cand[len])) {
                int bk = cand[len].back().se;
                if((ull)vh[atlit].hashInterval(m-len,m) == (ull)vh[bk].hashInterval(m-len,m)) {
                    ;
                } else {
                    udh[len] = 1;
                    continue;
                }
            }
            cand[len].push_back({i,atlit});
            // what_is("tes");
        }
    }
    vi ans(m,-1);
    ans[0] = cand[m][0].se;
    rep(i,1,m) {
        int id0 = cand[m-i][0].se;
        int ordi = ord[id0];
        // what_is(i);
        // what_is(id0);
        // int le=1, ri = sz(cand[m-i])-1;
        // int ats = 0;
        // while(le<=ri) {
        //     int mid = (le+ri)/2;
        //     bool ok = rmq.query(cand[m-i][0].fi+1, cand[m-i][mid].fi+1) >= m-i;
        //     if(ok) {
        //         ats = mid;
        //         le = mid+1;
        //     } else {
        //         ri = mid-1;
        //     }
        // }
        rep(j,1,sz(cand[m-i])) {
            // if ga sama, break
            // if(rmq.query(cand[m-i][j-1].fi+1,cand[m-i][j].fi+1) < m-i) {
            //     break;
            // }
            int idi = cand[m-i][j].se;
            // what_is(idi);
            if(ord[idi]<ordi) {
                id0 = idi;
                ordi = ord[idi];
            }
        }
        ans[i] = id0;
    }
    rep(i,0,m) {
        cout <<ans[i]+1 <<" \n"[i==m-1];
    }
    // for (int i = 0; i < SA.sa.size(); i++)
    // {
    //     SA.sa[i]
    // }
}

signed main()
{
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}