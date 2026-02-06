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

struct Node { // Splay tree. Root's pp contains tree's parent.
    Node *p = 0, *pp = 0, *c[2];
    bool flip = 0;
    int val, sum, valx, sumx;
    Node() { c[0] = c[1] = 0; fix(); }
    void fix() {
        if (c[0]) c[0]->p = this;
        if (c[1]) c[1]->p = this;
        // (+ update sum of subtree elements etc. if wanted)
        
    }
    void pushFlip() {
        if (!flip) return;
        flip = 0; swap(c[0], c[1]);
        if (c[0]) c[0]->flip ^= 1;
        if (c[1]) c[1]->flip ^= 1;
    }
    int up() { return p ? p->c[1] == this : -1; }
    void rot(int i, int b) {
        int h = i ^ b;
        Node *x = c[i], *y = b == 2 ? x : x->c[h], *z = b ? y : x;
        if ((y->p = p)) p->c[up()] = y;
        c[i] = z->c[i ^ 1];
        if (b < 2) {
            x->c[h] = y->c[h ^ 1];
            z->c[h ^ 1] = b ? x : this;
        }
        y->c[i ^ 1] = b ? this : x;
        fix(); x->fix(); y->fix();
        if (p) p->fix();
        swap(pp, y->pp);
    }
    void splay() { /// Splay this up to the root. Always finishes without flip set.
        for (pushFlip(); p; ) {
            if (p->p) p->p->pushFlip();
            p->pushFlip(); pushFlip();
            int c1 = up(), c2 = p->up();
            if (c2 == -1) p->rot(c1, 2);
            else p->p->rot(c2, c1 != c2);
        }
    }
    Node* first() { /// Return the min element of the subtree rooted at this, splayed to the top.
        pushFlip();
        return c[0] ? c[0]->first() : (splay(), this);
    }
};

struct LinkCut {
    vector<Node> node;
    LinkCut(int N) : node(N) {
        rep(i,0,N) {
            node[i].val = 1;
            node[i].sum = 1;
            node[i].valx = i;
            node[i].sumx = i;
        }
    }

    void link(int u, int v) { // add an edge (u, v)
        assert(!connected(u, v));
        makeRoot(&node[u]);
        node[u].pp = &node[v];
    }
    void cut(int u, int v) { // remove an edge (u, v)
        Node *x = &node[u], *top = &node[v];
        makeRoot(top); x->splay();
        assert(top == (x->pp ?: x->c[0]));
        if (x->pp) x->pp = 0;
        else {
            x->c[0] = top->p = 0;
            x->fix();
        }
    }
    bool connected(int u, int v) { // are u, v in the same tree?
        Node* nu = access(&node[u])->first();
        return nu == access(&node[v])->first();
    }
    void makeRoot(Node* u) { /// Move u to root of represented tree.
        access(u);
        u->splay();
        if(u->c[0]) {
            u->c[0]->p = 0;
            u->c[0]->flip ^= 1;
            u->c[0]->pp = u;
            u->c[0] = 0;
            u->fix();
        }
    }
    Node* access(Node* u) { /// Move u to root aux tree. Return the root of the root aux tree.
        u->splay();
        while (Node* pp = u->pp) {
            pp->splay(); u->pp = 0;
            if (pp->c[1]) {
                pp->c[1]->p = 0; pp->c[1]->pp = pp; }
            pp->c[1] = u; pp->fix(); u = pp;
        }
        return u;
    }

    void dbg() {
        rep(i,0,sz(node)) {
            cout <<i <<" " <<(node[i].pp? mp[node[i].pp]: -1) <<" " <<(node[i].p? mp[node[i].p]: -1) <<endl;
        }
    }
};

const int mxn=1e5;
const ll mod = 998244353;
int n,q;

void solve() {
    cin >>n >> q;
    vector<int> ans;
    ans.push_back(0);
    LinkCut lc(n);
    while(q--) {
        int a,b,c; cin >>a >>b >>c;
        a = 1+ ((1ll*a*(1+ans.back()))%mod)%2;
        b = 1 + ((1ll*b*(1+ans.back())%mod))%n;
        c = 1 + (1ll*c*(1+ans.back())%mod)%n;
        b--, c--;
        cout <<a <<" " <<b <<" " <<c <<endl;
        if(a==1) {
            lc.link(b, c);
        } else {
            lc.makeRoot(&lc.node[b]);
            lc.dbg();
            int valppc = (lc.par(&lc.node[c]) && lc.par(lc.par(&lc.node[c]))) ? lc.mp[(lc.par(lc.par(&lc.node[c])))] : -1;
            // int valppb = (lc.node[b].pp && lc.node[b].pp->pp) ? lc.mp[(lc.node[b].pp->pp)] : -1; 
            // bool samepp = lc.node[b].pp && lc.node[c].pp && lc.node[b].pp == lc.node[c].pp;           
            if(valppc == b) {
                ans.push_back(lc.mp[lc.par(&lc.node[c])] + 1);
            } else {
                ans.push_back(0);
            }
            // } else if(valppb == c) {
            //     ans.push_back(lc.mp[lc.node[b].pp] + 1);
            // } else if(samepp) {
            //     ans.push_back(lc.mp[lc.node[b].pp] + 1);
            // } 
            cout <<ans.back() <<endl;
        }
    }
    // rep(i,1,sz(ans)) {
    //     cout <<ans[i] <<"\n";
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}