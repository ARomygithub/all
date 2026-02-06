#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;

/**
 * Usage:
 * Monoset<less<pii>>
 * Monoset<greater<pii>>
 * 
 * update(idx, val, n-1) for Less<pii>
 * update(idx, val, 0) for Greater<pii>
 */
template<class T>
struct Monoset {
    private:
    set<pair<int, int>, T> poop;
    set<pair<int, int>> pooprev;
    int border;

    public:
    Monoset(int border): border(border), poop() {}

    int update(int index, int val) {
        auto pl = poop.lower_bound({index, 0});
        if (pl != poop.end() && pl->first == index) {
            pooprev.erase({pl->first, pl->second});
            poop.erase(pl);
        }

        poop.insert({index, val});
        pooprev.insert({val, index});

        auto ptr = poop.find({index, val});

        if (ptr != poop.begin()) {
            auto prev = ptr;
            prev--;
            if (ptr->second <= prev->second) {
                pooprev.erase({ptr->second, ptr->first});
                poop.erase(ptr);
                return index - 1;
            }
        }

        while(true) {
            auto nxt = ptr;
            nxt++;
            if (nxt == poop.end()) break;
            if (nxt->second <= ptr->second) {
                pooprev.erase({nxt->first, nxt->second});
                poop.erase(nxt);
            }
            else break;
        }

        auto laptr = poop.find({index, val});
        if (laptr == poop.end()) return index-1;
        laptr++;
        if (laptr == poop.end()) return border;
        return laptr->first;
    }

    pii search(int val) {
        auto p = pooprev.lower_bound({val, 0});
        return {p->second, p->first};
    }

    stack<pii> get() {
        stack<pii> res;
        for (pair<int, int> x: poop) {
            res.push(x);
        }
        return res;
    }
};

const int inf = 1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = -1, madd = 0, val = 0;
    Node(int lo, int hi):lo(lo),hi(hi){}
    Node(vi& v, int lo, int hi): lo(lo), hi(hi) {
        if (lo+1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node (v, lo, mid); r = new Node (v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    int sum() {
        return query(lo, hi);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val = x*(hi-lo), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void sett(int L, int R, int x) {
        if (L > R) return;
        // cout << "SET " << L << "-" << R << ": " << x << endl;
        set(L, R+1, x);
    }
    void push() {
        if (!l) {
            int mid = lo + (hi-lo) / 2;
            l = new Node(lo ,mid); r = new Node(mid, hi);
        }
        if (mset != -1) 
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = -1;
    }
};

void solve() {
    cin >> n;
    vi vec(n);
    rep(i, 0, n) cin >> vec[i];

    Monoset<less<pii>> L(n);
    Monoset<greater<pii>> R(-1);

    int TOT = 0;
    rep(i, 0, n) TOT += vec[i];
    rep(i, 0, n) {
        L.update(i, vec[i]);
        R.update(i, vec[i]);
    }

    // initialize segtree
    vi lrmin(n);
    int pl = 0;
    rep(i, 0, n) {
        pl = max(pl, vec[i]);
        lrmin[i] = pl;
    }
    pl = 0;
    for (int i = n-1; i >= 0; i--) {
        pl = max(pl, vec[i]);
        lrmin[i] = min(lrmin[i], pl);
    }
    Node seg(lrmin, 0, n);

    // use segtree
    // cout << "seg sum: " << seg.sum() << endl;

    int q; cin >> q;
    while(q--) {
        int x, v; cin >> x >> v;
        x--;
        vec[x] += v;
        TOT += v;
        
        int range = L.update(x, vec[x]) - 1;
        // cout << "range l: " << range << endl;
        // cout << "stack: " << endl;
        // auto stkL = L.get();
        // while(stkL.size()) {
        //     cout << stkL.top().first << ' ' << stkL.top().second << endl;
        //     stkL.pop();
        // }
        if (range >= x) {
            pii po = R.search(vec[x]);
            // cout << "po " << po.first << ' ' << po.second << endl;
            int ll = x, rr = min(range, po.first);
            seg.sett(ll, rr, vec[x]);
        }

        range = R.update(x, vec[x]) + 1;
        // cout << "range r: " << range << endl;
        // cout << "stack: " << endl;
        // auto stk = R.get();
        // while(stk.size()) {
        //     cout << stk.top().first << ' ' << stk.top().second << endl;
        //     stk.pop();
        // }
        if (range <= x) {
            pii po = L.search(vec[x]);
            int ll = max(range, po.first), rr = x;
            seg.sett(ll, rr, vec[x]);
        }

        // cout << seg.sum() << endl;
        // cout << TOT << endl;
        // rep(i, 0, n) {
        //     cout << seg.query(i, i+1) << ' ';
        // }
        // cout << endl;
        cout << seg.sum() - TOT << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}