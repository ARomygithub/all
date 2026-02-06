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

const int mxn=2e5;
int n,q;

struct Node {
    Node* l = 0;
    Node* r = 0;
    int val;
    Node(int val): val(val) {}
};

void solve() {
    cin >>n;
    vector<Node*> v;
    rep(i,0,n) {
        int val; cin >>val;
        Node* cur = new Node(val);
        v.push_back(cur);
    }
    map<int,Node*> mp;
    rep(i,0,n) {
        if(i>0) {
            v[i]->l = v[i-1];
        }
        if(i+1<n) {
            v[i]->r = v[i+1];
        }
        mp[v[i]->val] = v[i];
    }
    Node* st = v[0];
    cin >>q;
    auto add = [&](int x, int y) -> void {
        Node* cur = mp[x];
        if(cur->r) {
            Node* nz = cur->r;
            Node* ny = new Node(y);
            cur->r = ny;
            ny->l = cur;
            ny->r = nz;
            nz->l = ny;
            mp[y] = ny;
        } else {
            Node* ny = new Node(y);
            cur->r = ny;
            ny->l = cur;
            mp[y] = ny;
        }
    };
    auto rem = [&](int x) -> void {
        Node* cur = mp[x];
        if(cur==st) {
            st = cur->r;
            st->l = 0;
            cur->r = 0;
        } else if(cur->r) {
            Node* nl = cur->l;
            Node* nr = cur->r;
            nl->r = nr;
            nr->l = nl;
            cur->l = 0;
            cur->r = 0;
        } else { // end
            Node* nl = cur->l;
            nl->r = 0;
            cur->l = 0;
        }
        delete cur;
        mp.erase(x);
    };
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,y; cin >>x >>y;
            add(x,y);
        } else {
            int x; cin >>x;
            rem(x);
        }
    }
    Node* u = st;
    while(u) {
        int x = 0;
        if(u->r) {
            x = 0;
        } else {
            x = 1;
        }
        cout <<u->val <<" \n"[x];
        u = u->r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}