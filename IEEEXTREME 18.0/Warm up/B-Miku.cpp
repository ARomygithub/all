#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

// const int MOD = 1000000007;
const int MOD = 998244353;

struct SegmentTree {
    struct Node {
        int f, u, a;
        int fu, uf, fa, af;
        int faf, fuf;

        Node(int f = 0, int u = 0, int a = 0, int fu = 0, int uf = 0, int fa = 0, int af = 0, int faf = 0, int fuf = 0): f(f), u(u), a(a), fu(fu), uf(uf), fa(fa), af(af), faf(faf), fuf(fuf) {}
    
        void print() {
            debug(f);
            debug(u);
            debug(a);
            debug(fu);
            debug(uf);
            debug(fa);
            debug(af);
            debug(faf);
            debug(fuf);

            cout << endl;
        }
    };
    const Node ZERO = Node();
    const Node _f = Node(1);
    const Node _u = Node(0, 1);
    const Node _a = Node(0, 0, 1);

    Node merge(Node a, Node b) {
        return Node(
            (a.f + b.f) % MOD, 
            (a.u + b.u) % MOD, 
            (a.a + b.a) % MOD, 
            (a.fu + b.fu + a.f * b.u) % MOD,
            (a.uf + b.uf + a.u * b.f) % MOD,
            (a.fa + b.fa + a.f * b.a) % MOD,
            (a.af + b.af + a.a * b.f) % MOD,
            (a.faf + b.faf + a.fa * b.f + a.f * b.af) % MOD,
            (a.fuf + b.fuf + a.fu * b.f + a.f * b.uf) % MOD
        );
    }

    int n;
    vector<Node> seg;

    SegmentTree(int n): seg(n * 4, ZERO), n(n) {}


    Node query(int idx, int l, int r, int x, int y) {
        if (l > y || x > r) return ZERO;
        if (x <= l && r <= y) return seg[idx];
        int mid = (l + r) / 2, lc = idx * 2, rc = idx * 2 + 1;

        // cout << "RANGE " << l << " " << r << endl;
        // seg[idx].print();

        return merge(query(lc, l, mid, x, y), query(rc, mid+1, r, x, y));   
    }

    Node query(int x, int y) {
        return query(1, 0, n-1, x, y);
        // return query(1, 1, n, x, y);
    }

    void update(int idx, int l, int r, int x, Node v) {
        if (l > x || x > r) return;
        if (x <= l && r <= x) {
            seg[idx] = v;
            return;
        }
        int mid = (l + r) / 2, lc = idx * 2, rc = idx * 2 + 1;

        update(lc, l, mid, x, v);
        update(rc, mid+1, r, x, v);
        seg[idx] = merge(seg[lc], seg[rc]);
    }

    void update(int x, Node v) {
        update(1, 0, n-1, x, v);
        // update(1, 1, n, x, y, v);
    }

};



void solve() {
    int n, q; cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree seg(n + 5);
    forn(i, n) {
        if (s[i] == 'F') {
            seg.update(i, seg._f);
        }
        else if (s[i] == 'A') {
            seg.update(i, seg._a);
        }
        else if (s[i] == 'U') {
            seg.update(i, seg._u);
        }
        else {
            seg.update(i, seg.ZERO);
        }
    }

    forn(t, q) {
        int c; cin >> c;
        if (c == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            --pos;
            if (c == 'F') {
                seg.update(pos, seg._f);
            }
            else if (c == 'A') {
                seg.update(pos, seg._a);
            }
            else if (c == 'U') {
                seg.update(pos, seg._u);
            }
            else {
                seg.update(pos, seg.ZERO);
            }
        }
        else if (c == 2) {
            int l, r; cin >> l >> r;
            --l;--r;
            cout << seg.query(l, r).fuf << endl;
        }
        else {
            int l, r; cin >> l >> r;
            --l;--r;
            cout << seg.query(l, r).faf << endl;

        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}